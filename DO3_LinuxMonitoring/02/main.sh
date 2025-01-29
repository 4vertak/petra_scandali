#!/bin/bash

# ================================================
# 1. ФУНКЦИИ ДЛЯ КОНВЕРТАЦИИ РАЗМЕРА и МАСКИ
# ================================================

# КОНВЕРТАЦИЯ CIDR в IPv4
cidr_to_mask() {
  local CIDR="$1"
  local MASK=""
  for ((i=0; i<4; i++)); do
    if [ "$CIDR" -ge 8 ]; then
      MASK+="255"
      CIDR=$((CIDR - 8))
    else
      MASK+="$((256 - (2 ** (8 - CIDR))))"
      CIDR=0
    fi
    [ "$i" -lt 3 ] && MASK+="."
  done
  echo "$MASK"
}

# КОНВЕРТАЦИЯ РАЗМЕРА
convert_size() {
    local VALUE=$1
    echo "scale=$2; $VALUE / 1024" | bc
}

# ================================================
# 2. ФОРМИРОВАНИЕ ВЫВОДА
# ================================================

# СЕТЕВОЕ ИМЯ
HOSTNAME=$(hostname)

#ВРЕМЕННАЯ ЗОНА и СМЕЩЕНИЕ ВРЕМЕНИ в виде: America/New_York UTC -5
TIMEZONE=$(timedatectl show --property=Timezone --value )
UTC_OFFSET=$(date +%:z | sed 's/^+0/+/; s/^-0/-/; s/^00/0/; s/:00$//')
TIMEZONE_INFO="$TIMEZONE UTC ${UTC_OFFSET}"

USER=$(whoami)

#ИНФОРМАЦИЯ ОБ ОСи
OS=$(awk -F'"' '{print $2}' /etc/os-release | head -1)

# ТЕКУЩЕЕ ВРЕМЯ в виде: 12 May 2020 12:24:36
DATE=$(date +"%d %B %Y %T")

# ВРЕМЯ РАБОТЫ СИСТЕМЫ 
UPTIME=$(uptime -p | sed 's/up //')

# ВРЕМЯ РАБОТЫ СИСТЕМЫ в секундах
UPTIME_SEC=$(cat /proc/uptime | awk '{print $1}' | cut -d '.' -f 1)

#СЕТЕВЫЕ НАСТРОЙКИ
INTERFACE=$(ip -o -4 addr show | grep -v ' lo ' | awk '{print $2}' | head -n1)
IP_INFO=$(ip -o -4 addr show "$INTERFACE" | awk '{print $4}')
IP=$(echo "$IP_INFO" | cut -d'/' -f1)
CIDR=$(echo "$IP_INFO" | cut -d'/' -f2)
MASK=$(cidr_to_mask "$CIDR")
GATEWAY=$(ip route | grep default | awk '{print $3}')

# ПАМЯТЬ ОПЕРАТИВКА
RAM_TOTAL=$(convert_size $(free --si --mega | awk '/^Mem:/{print $2}') 3)
RAM_USED=$(convert_size $(free --si --mega | awk '/^Mem:/{print $3}') 3)
RAM_FREE=$(convert_size $(free --si --mega | awk '/^Mem:/{print $4}') 3)

# ПАМЯТЬ КОРНЕВОЙ РАЗДЕЛ
SPACE_ROOT=$(convert_size $(df -BK / | awk 'NR==2 {print substr($2, 1, length($2)-1)}') 2)
SPACE_ROOT_USED=$(convert_size $(df -BK / | awk 'NR==2 {print substr($3, 1, length($3)-1)}') 2)
SPACE_ROOT_FREE=$(convert_size $(df -BK / | awk 'NR==2 {print substr($4, 1, length($4)-1)}') 2)

# ================================================
# 3. ВЫВОД ИНФОРМАЦИИ
# ================================================

output="HOSTNAME = $HOSTNAME
TIMEZONE = $TIMEZONE_INFO
USER = $USER
OS = $OS
DATE = $DATE
UPTIME = $UPTIME
UPTIME_SEC = $UPTIME_SEC
IP = $IP
MASK = $MASK
GATEWAY = $GATEWAY
RAM_TOTAL = ${RAM_TOTAL} GB
RAM_USED = ${RAM_USED} GB
RAM_FREE = ${RAM_FREE} GB
SPACE_ROOT = ${SPACE_ROOT} MB
SPACE_ROOT_USED = ${SPACE_ROOT_USED} MB
SPACE_ROOT_FREE = ${SPACE_ROOT_FREE} MB"

echo "$output"

# ================================================
# 4. СОХРАНЕНИЕ ИНФОРМАЦИИ
# ================================================

read -p "Хотите сохранить данные в файл? (Y/N): " answer
if [[ "$answer" =~ ^[Yy]$ ]]; then
  filename=$(date +"%d_%m_%y_%H_%M_%S").status
  echo "$output" > "$filename"
  echo "Данные сохранены в файл $filename"
else
    echo "Данные не были сохранены."
fi

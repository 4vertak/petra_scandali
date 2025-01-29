#!/bin/bash

# ================================================
# 1. НАСТРОЙКА ЦВЕТОВ И ПРОВЕРКА ПАРАМЕТРОВ
# ================================================

#Декларация ЦВЕТов
declare -A colors=(
    [1]='\033[97m'  # white
    [2]='\033[91m'  # red
    [3]='\033[92m'  # green
    [4]='\033[94m'  # blue
    [5]='\033[95m'  # purple
    [6]='\033[90m'  # black
)

declare -A backgrounds=(
    [1]='\033[107m' # white
    [2]='\033[101m' # red
    [3]='\033[102m' # green
    [4]='\033[104m' # blue
    [5]='\033[105m' # purple
    [6]='\033[40m'  # black
)

# ПРОВЕРЯЕМ КОЛ-ВО ПАРМЕТРов
if [ "$#" -ne 4 ]; then
    echo "Ошибка: требуется 4 параметра."
    echo "Использование: $0 <фон_имен> <цвет_шрифта_имен> <фон_значений> <цвет_шрифта_значений>"
    exit 1
fi

# ПРОВЕРЯЕМ НА КОРРЕКТНОСТЬ ПАРАМЕТРОВ
for param in "$BACKGROUND_NAME" "$FONT_COLOR_NAME" "$BACKGROUND_VALUE" "$FONT_COLOR_VALUE"; do
    if ! [[ "$param" =~ ^[1-6]$ ]]; then
        echo "Ошибка: все параметры должны быть числовыми значениями от 1 до 6."
        exit 1
    fi
done

BACKGROUND_NAME=$1
FONT_COLOR_NAME=$2
BACKGROUND_VALUE=$3
FONT_COLOR_VALUE=$4

# ================================================
# 2. ФУНКЦИИ ДЛЯ РАБОТЫ С ЦВЕТАМИ
# ================================================

# ПРОВЕРЯЕМ НА СОВПАДЕНИЕ ЦВЕТОВ ФОНА и ШРИВТА
if [ "$BACKGROUND_NAME" -eq "$FONT_COLOR_NAME" ]; then
    echo "Ошибка: фон имен не должен совпадать с цветом шрифта имен."
    exit 1
fi

if [ "$BACKGROUND_VALUE" -eq "$FONT_COLOR_VALUE" ]; then
    echo "Ошибка: фон значений не должен совпадать с цветом шрифта значений."
    exit 1
fi

# ================================================
# 3. ФУНКЦИИ ДЛЯ КОНВЕРТАЦИИ РАЗМЕРА и МАСКИ
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
# 4. ФОРМИРОВАНИЕ ВЫВОДА
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
# 4. ВЫВОД ИНФОРМАЦИИ
# ================================================

reset='\033[0m'
output=""
for label in "HOSTNAME" "TIMEZONE" "USER" "OS" "DATE" "UPTIME" "UPTIME_SEC" "IP" "MASK" "GATEWAY" "RAM_TOTAL" "RAM_USED" "RAM_FREE" "SPACE_ROOT" "SPACE_ROOT_USED" "SPACE_ROOT_FREE"; do
    value=$(eval "echo \$$label")
    output+="${backgrounds[$BACKGROUND_NAME]}${colors[$FONT_COLOR_NAME]}${label} = ${backgrounds[$BACKGROUND_VALUE]}${colors[$FONT_COLOR_VALUE]}${value}${reset}\n"
done

echo -e "$output"

#!/bin/bash

cidr_to_decimal() {
    local CIDR=$1

    BIT_STRING=$(printf '%0'${CIDR}'s' | tr ' ' '1')$(printf '%0'$((32-CIDR))'s' | tr ' ' '0')

    OCTETS=""
    for (( i=0; i<4; i++ )); do
        OCTET=${BIT_STRING:0:8}
        BIT_STRING=${BIT_STRING:8}
        
        DECIMAL=$((2#$OCTET))
        
        OCTETS+="$DECIMAL"
        if [ $i -lt 3 ]; then
            OCTETS+="."
        fi
    done

    echo "$OCTETS"
}

convert_size() {
    local mb_value=$1
    echo "scale=$2; $mb_value / 1024" | bc
}


HOSTNAME=$(hostname)
TIMEZONE=$(timedatectl show --property=Timezone --value)
UTC_OFFSET=$(date +%:z)
USER=$(whoami)

OS=$(awk -F'"' '{print $2}' /etc/os-release | head -1)
DATE=$(date +"%d %B %Y %T")

UPTIME=$(uptime -p | sed 's/up //')
UPTIME_SEC=$(cat /proc/uptime | awk '{print $1}' | cut -d '.' -f 1)

IP=$(hostname -I | awk '{print $1}') 
MASK=$(cidr_to_decimal $(ip addr show | grep -w "$IP" -A 2 | grep -oP '(?<=inet\s)\d+(\.\d+){3}\/\d+' | awk -F'/' '{print $2}'))
GATEWAY=$(ip route | grep default | awk '{print $3}')

RAM_TOTAL=$(convert_size $(free --si --mega | awk '/^Mem:/{print $2}') 3)
RAM_USED=$(convert_size $(free --si --mega | awk '/^Mem:/{print $3}') 3)
RAM_FREE=$(convert_size $(free --si --mega | awk '/^Mem:/{print $4}') 3)

SPACE_ROOT=$(convert_size $(df -BK / | awk 'NR==2 {print substr($2, 1, length($2)-1)}') 2)
SPACE_ROOT_USED=$(convert_size $(df -BK / | awk 'NR==2 {print substr($3, 1, length($3)-1)}') 2)
SPACE_ROOT_FREE=$(convert_size $(df -BK / | awk 'NR==2 {print substr($4, 1, length($4)-1)}') 2)

echo "HOSTNAME = $HOSTNAME"
echo "TIMEZONE = $TIMEZONE $UTC_OFFSET"
echo "USER = $USER"
echo "OS = $OS"
echo "DATE = $DATE"
echo "UPTIME = $UPTIME"
echo "UPTIME_SEC = $UPTIME_SEC"
echo "IP = $IP"
echo "MASK = $MASK"
echo "GATEWAY = $GATEWAY"
echo "RAM_TOTAL = $RAM_TOTAL GB"
echo "RAM_USED = $RAM_USED GB"
echo "RAM_FREE = $RAM_FREE GB"
echo "SPACE_ROOT = $SPACE_ROOT MB"
echo "SPACE_ROOT_USED = $SPACE_ROOT_USED MB"
echo "SPACE_ROOT_FREE = $SPACE_ROOT_FREE MB"

read -p "Хотите сохранить данные в файл? (Y/N): " answer
if [[ "$answer" =~ ^[Yy]$ ]]; then
    filename=$(date +"%d_%m_%y_%H_%M_%S.status")
    {
        echo "HOSTNAME = $HOSTNAME"
        echo "TIMEZONE = $TIMEZONE $UTC_OFFSET"
        echo "USER = $USER"
        echo "OS = $OS"
        echo "DATE = $DATE"
        echo "UPTIME = $UPTIME"
        echo "UPTIME_SEC = $UPTIME_SEC"
        echo "IP = $IP"
        echo "MASK = $MASK"
        echo "GATEWAY = $GATEWAY"
        echo "RAM_TOTAL = $RAM_TOTAL GB"
        echo "RAM_USED = $RAM_USED GB"
        echo "RAM_FREE = $RAM_FREE GB"
        echo "SPACE_ROOT = $SPACE_ROOT MB"
        echo "SPACE_ROOT_USED = $SPACE_ROOT_USED MB"
        echo "SPACE_ROOT_FREE = $SPACE_ROOT_FREE MB"
    } > "$filename"
    echo "Данные сохранены в файл $filename."
else
    echo "Данные не были сохранены."
fi
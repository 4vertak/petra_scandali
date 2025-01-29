#!/bin/bash

echo''
line="Welcome, young Padawan, to the Bash scripting dojo! Let's start creating a directory and files to turn it."
len=${#line}
for ((i=0; i<len; i++)); do
    printf "\e[1;33m${line:$i:1}\e[0m"
    sleep 0.1
done

while true; do
    read -p "Write the relative path ('./src/' or './'):" path
    if [ -d "$path" ]; then
        break
    else
        echo "No such directory"
        continue
    fi
done

for ((i=1; i<6; i++))
do
    mkdir "$path"0$i
    touch "$path"0$i/main.sh
done

echo ''
line="And may the Bash-Force be with you!"
len=${#line}
for ((i=0; i<len; i++)); do
    printf "\e[1;33m${line:$i:1}\e[0m"
    sleep 0.1
done
echo ''
echo ''
#!/bin/bash

frame_text() {
    local text="$1"
    local max_length=50
    while IFS= read -r line; do
        if [ ${#line} -gt $max_length ]; then
            max_length=${#line}
        fi
    done <<< "$text"
    local border=$(printf '%0.s═' $(seq 1 $((max_length + 2))))
    printf "\e[1;33m╔%s╗\n" "$border"
    while IFS= read -r line; do
        printf "║ %-${max_length}s ║\n" "$line"
    done <<< "$text"
    printf "\e[1;33m╚%s╝\e[0m\n" "$border"
}

MUSIC_FILE=$(echo "$(realpath "$0" | sed 's/run_scripts.sh/music/')start.mp3")

if command -v rhythmbox >/dev/null 2>&1; then
    rhythmbox &
    sleep 2
    if command -v rhythmbox-client >/dev/null 2>&1; then
        rhythmbox-client --play-uri "file://$MUSIC_FILE" 2>/dev/null
    fi
fi
wait


echo ''
line="A long time ago in a shell far, far away..."
len=${#line}
for ((i=0; i<len; i++)); do
    printf "\e[1;33m${line:$i:1}\e[0m"
    sleep 0.1
done
echo ''
echo ''

for ((i=1; i<6; i++))
do
    chmod +x ./0$i/main.sh
    echo ''
    frame_text "Execution of script 0$i"

    if [ $i -eq 1 ]; then
        bash ./0$i/main.sh "hello"
    elif [ $i -eq 2 ] || [ $i -eq 4 ]; then
        bash ./0$i/main.sh
    elif [ $i -eq 3 ]; then
        bash "./0$i/main.sh" '1' '2' '3' '4'
    else
        bash "./0$i/main.sh" ../src/
    fi
    echo ''
    sleep 0.1
done

line="And may the Bash-Force be with you!"
len=${#line}
for ((i=0; i<len; i++)); do
    printf "\e[1;33m${line:$i:1}\e[0m"
    sleep 0.1
done
echo ''
#!/bin/bash

echo''
line="Let's start creating a directory and files to turn it."
len=${#line}
for ((i=0; i<len; i++)); do
    printf "\e[1;33m${line:$i:1}\e[0m"
    sleep 0.1
done
echo''
echo''

individual_message="1. Individual project"
group_message="2. Group project"

while true; do
    read -p "Enter 1. Individual project or 2. Group project: " project
    if [[ $project == 1 || $project == 2 ]]; then
        break
    else
        echo "Invalid input. Please enter 1 or 2."
        continue
    fi
done

while true; do
    if [[ $project == 1 ]]; then
        read -p "Enter the day number (0-10): " project_num
    else
        read -p "Enter the project number (0-1): " project_num
    fi

    read -p "Continue? (Y/N): " confirm && [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]] || exit 1

    if (( ($project == 1 && ( $project_num >= 0 && $project_num <= 10 )) || ($project == 2 && ($project_num == 0 || $project_num == 1)) )); then
        break
    else
        echo "Invalid input. Please enter a valid number"
        continue
    fi
done

while true; do
    read -p "Enter the number of exercises (0-20): " num_ex
    read -p "Continue? (Y/N): " confirm && [[ $confirm == [yY] || $confirm == [yY][eE][sS] ]] || exit 1
    if [[ $num_ex =~ ^[0-9]$|^1[0-9]$|^20$ ]]; then
        break
    else
        echo "Invalid input. Please enter a valid number."
        continue
    fi
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

for ((i=0; i<$num_ex + 1; i++))
do
    if [ $project == 1 ]; then
        if [ $i -lt 10 ]; then
            mkdir "$path"ex0$i
            touch "$path"ex0$i/day0$project_num'_ex0'$i.sql
        elif [ $i -ge 10 ]; then
            mkdir "$path"ex$i
            touch "$path"ex$i/day$project_num'_ex'$i.sql
        fi
    else
        if [ $i -lt 10 ]; then
            mkdir "$path"ex0$i
            touch "$path"ex0$i/team0$project_num'_ex0'$i.sql
        elif [ $i -ge 10 ]; then
            mkdir "$path"ex$i
            touch "$path"ex$i/team$project_num'_ex'$i.sql
        fi
    fi
done


echo''
line="And may the SQL-Force be with you!"
len=${#line}
for ((i=0; i<len; i++)); do
    printf "\e[1;33m${line:$i:1}\e[0m"
    sleep 0.1
done
echo ''
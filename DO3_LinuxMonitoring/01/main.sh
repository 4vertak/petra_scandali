#!/bin/bash

ISDIGIT="^[0-9]+$"
if [[ $1 == "" ]]; then
    echo "Введите текстовый параметр" >&2; exit 1
elif [[ $1 =~ $ISDIGIT ]]; then
    echo "Некорректный ввод: должен быть текстовый параметр" >&2; exit 1
else 
    echo "$1"
fi
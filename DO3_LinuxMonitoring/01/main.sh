#!/bin/bash

ISDIGIT="^[0-9]+$"
if [[ $1 =~ $ISDIGIT ]];
    then echo "invalid input" >&2; exit 1
else 
    echo "$1"
fi
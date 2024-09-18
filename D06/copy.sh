#!/bin/bash

USER_NAME="woodysyl"
HOST_NAME="10.10.0.2"
DIR="/usr/local/bin"

printf "\033[1;33mCopying s21_cat to $USER_NAME@$HOST_NAME:$DIR \n\033[0m"
scp ./artifacts/s21_cat $USER_NAME@$HOST_NAME:$DIR
if [ $? -ne 0 ]; then
printf "\033[1;33mError copying s21_cat\n\033[0m"
exit 1
fi

printf "\033[1;33mCopying s21_grep to $USER_NAME@$HOST_NAME:$DIR \n\033[0m"
scp ./artifacts/s21_grep $USER_NAME@$HOST_NAME:$DIR
if [ $? -ne 0 ]; then
printf "\033[1;33mError copying s21_grep\n\033[0m"
exit 1
fi

printf "\033[1;33mDeploy completed successfully\n\033[0m"
printf "$USER_NAME@$HOST_NAME:$DIR ls\n"
ssh $USER_NAME@$HOST_NAME ls $DIR
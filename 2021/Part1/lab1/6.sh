#!/bin/bash

if [ "$PWD" == "$HOME" ] 
then
pwd
exit 0
else
echo -e "\033[31mNOT HOME DIR\033[37m"
exit 1
fi

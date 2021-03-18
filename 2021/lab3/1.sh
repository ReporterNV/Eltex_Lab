#!/bin/bash
SEARCHNAME="student"

ps -a -u "$SEARCHNAME" -o "pid,comm" | sed 's/\s//' | sed 's/\s/:/'

#!/bin/bash

FILENAME="Output_lab3"
ps -ax -o pid,command | grep "\s/sbin" | grep -Eo "\s[0-9]{1,}\s" > $FILENAME




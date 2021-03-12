#!/bin/bash

grep -Eho '\b[A-Za-z0-9]{1,}@[A-Za-z0-9]{1,}\..*\b'  /etc/* 2> /dev/null | tr '\n' ',' | sed 's/,$/\n/' > emails.lst

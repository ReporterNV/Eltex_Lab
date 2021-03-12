#!/bin/bash
grep -h -E "^ACPI.*" /var/log/* 1> errors.log 2> /dev/null 
grep -E "^.*/[A-Za-z0-9].*$" ./errors.log


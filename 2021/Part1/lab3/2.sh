#!/bin/bash
#Да, я не использовал встр сортировку и да я перепроверял по времени запуска
ps -ax -o pid,start | sort -k2 | grep -Eo "^ [0-9]{1,}"




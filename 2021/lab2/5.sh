#!/bin/bash

#Ьлин. Обидно будет если я забуду как я это делаю. Надо будет себе в заметки выписать.

#Опечатка в условии задачи: Сведения о пользователей -> Сведения о пользователях
cat /etc/passwd | awk -F: '{print $1" " $3}' | sort -k2

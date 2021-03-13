#!/bin/bash

echo 'All scripts in /bin :'
#grep -lE '^#!' /bin/* 2>/dev/null != grep -E '^#!' /bin/* > /dev/null 
# Появляются лишния файла при -El(тк бинарник совпадает с текстом?)

grep -Esl '^#!/' /bin/* # Вывод всех скриптов в /bin/ 

#Как это воспринимать?: 
#!/usr/bin/env python3
#Это python или env для нашей программы? Те надо будет раскрыть путь до 
echo 'Most used interpreter:'
grep -Ehs '^#!/' /bin/* | sort | uniq -c | sort -r | grep -Eo '/.*$' | head -n 1
#Почти сутки потратил. Оказалось, что uniq может получить кол-во встречающихся строк. А дальше все просто.


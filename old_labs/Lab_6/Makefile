indent: ./Source/*.c
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux ./Source/*.c	
Lab: ./Source/Lab.c 
	gcc -std=c99 ./Source/Lab.c -o Lab 
Labtest: ./Source/Lab.c 
	gcc -std=c99 ./Source/Lab.c -o Lab && ./Lab example 
clear: 
	rm Lab 

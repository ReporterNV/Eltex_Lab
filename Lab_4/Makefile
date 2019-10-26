indent: *.c
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux *.c	
Lab2test: Lab2.c 
	gcc -Wall -g -std=c99 Lab2.c -o Lab2 && ./Lab2 < custom.txt
Lab2: Lab2.c 
	gcc -Wall -g -std=c99 Lab2.c -o Lab2 && ./Lab2 
Lab1test: Lab1.c
	gcc -Wall -g -std=c99 Lab1.c -o Lab1 && ./Lab1 < custom.txt 
Lab1: Lab1.c
	gcc -Wall -g -std=c99 Lab1.c -o Lab1 && ./Lab1 
clean: 
	rm Lab2 Lab1 

indent: /Source/*.c
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux ./Source/*.c	

Lab2: ./Source/Lab2
	gcc -Wall -g -std=c99 Lab2.c -o ./Source/Lab2 && ./Lab2 < example

Lab1: ./Source/Lab1.c
	gcc -Wall -g -std=c99 Lab1.c -o ./Source/Lab1 && ./Lab1 < example

clean: 
	rm Lab2 Lab1 

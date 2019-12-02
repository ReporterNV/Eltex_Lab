indent: ./Source/*.c
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux ./Source/*.c	

Lab2test: ./Source/Lab2.c 
	gcc -Wall -g -std=c99 ./Source/Lab2.c -o Lab2 && ./Lab2 example 2 && echo "IN:" && cat example && echo "OUT:" &&  cat example.out 

Lab2: ./Source/Lab2.c 
	gcc -Wall -g -std=c99 ./Source/Lab2.c -o Lab2

Lab1test: ./Source/Lab1.c
	gcc -Wall -g -std=c99 ./Source/Lab1.c -o Lab1 && ./Lab1 example A && echo "IN:" && cat example && echo "OUT:" &&  cat example.out  

Lab1: ./Source/Lab1.c
	gcc -Wall -g -std=c99 ./Source/Lab1.c -o Lab1 

clear: 
	rm Lab2 Lab1 

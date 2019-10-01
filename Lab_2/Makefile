Lab_2: Lab.c
	gcc -Wall -g -std=c99 Lab.c -o Lab_2
run: Lab_2
	./Lab_2
runtest: Lab_2
	./Lab_2 < text.txt
rundb: Lab_2
	gdb ./Lab_2
clean: 
	rm Lab_2 a.out 
indent: *.c
	indent -kr -i8 -ts8 -sob -l80 -ss -bs-linux *.c	

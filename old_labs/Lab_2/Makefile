Lab_2: ./Source/Lab.c
	gcc -Wall -g -std=c99 ./Source/Lab.c -o Lab_2

run: Lab_2
	./Lab_2

clear: 
	rm Lab_2 a.out custom.txt gen 

gen: ./Source/gen.c
	gcc -Wall -std=c99 ./Source/gen.c -o gen 

example: gen
	./gen 100 10 

ctest: custom.txt Lab_2
	time (./Lab_2 < example) 

old: ./Source/Lab_OLD.c
	gcc -std=c99 ./Source/Lab_OLD.c && time ./a.out < example 
	
indent: 
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux ./Source/*.c	

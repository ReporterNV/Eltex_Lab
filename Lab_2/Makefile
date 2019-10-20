Lab_2: Lab.c
	gcc -Wall -g -std=c99 Lab.c -o Lab_2
run: Lab_2
	./Lab_2
rundb: Lab_2
	gdb ./Lab_2
clean: 
	rm Lab_2 a.out custom.txt gen 
gen: gen.c
	gcc -Wall -std=c99 gen.c -o gen 
custom.txt: gen
	./gen 100000 
ctest: custom.txt Lab_2
	time ./Lab_2 < custom.txt 
regen: gen
	rm custom.txt && ./gen 10000000
indent: *.c
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux *.c	

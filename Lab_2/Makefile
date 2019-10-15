Lab_2: Lab.c
	gcc -Wall -g -std=c99 Lab.c -o Lab_2
run: Lab_2
	./Lab_2
test: Lab_2
	./Lab_2 < text.txt
rundb: Lab_2
	gdb ./Lab_2
clean: 
	rm Lab_2 a.out 
gen: gen.c
	gcc -Wall -g -std=c99 gen.c -o gen 
custom.txt: gen
	./gen 10 
ctest: custom.txt Lab_2
	time ./Lab_2 < custom.txt && rm custom.txt
indent: *.c
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux *.c	

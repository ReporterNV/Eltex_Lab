indent: *.c
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux *.c	
Lab1: Lab1.c
	gcc -c Lab1.c -o Lab.o && ar rc libstat.a Lab.o && ranlib libstat.a 
Lab2: Lab2.c 
	gcc -Wall -g -l stat -L. -std=c99 Lab2.c -o Lab2  
Lab2test: libstat.a Lab2
	./Lab2 
Lab3: Lab1.c 
	gcc -Wall -fPIC -shared  Lab1.c -o Lab1.so
Lab3test: Lab1.c Lab2.c
	gcc -fPIC -shared  Lab1.c -o libDLL.so && gcc Lab2.c -o Lab2 -L. -lDLL -Wl,-rpath,. 
clean: 
	rm Lab2 Lab1 

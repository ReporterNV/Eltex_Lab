indent: *.c
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux *.c	
Lab1 libstat.a: Lab1.c
	gcc -c Lab1.c -o Lab.o && ar rc libstat.a Lab.o && ranlib libstat.a 
Lab2: Lab2.c libstat.a 
	gcc -Wall -g  Lab2.c -lstat -L. -std=c99 -o Lab2  
Lab2test: libstat.a Lab2
	./Lab2 
Lab3: Lab1.c Lab2.c 
	gcc -fPIC -shared  Lab1.c -o libDLL.so && gcc Lab2.c -o Lab3 -L. -lDLL -Wl,-rpath,. 
	gcc -Wall -fPIC -shared  Lab1.c -o Lab1.so
Lab3test: Lab3
	./Lab3	
clean: 
	rm Lab2 Lab1 Lab3 *.a *.o *.so 

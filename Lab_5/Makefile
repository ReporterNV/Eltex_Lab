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
Lab3test: Lab3
	./Lab3	
Lab4: Lab3.c Lab4.c 
	gcc -shared -o libDLL.so -fPIC Lab1.c && gcc Lab4.c -o Lab4 -ldl 
Lab4test: Lab4
	./Lab4	
clean: 
	rm Lab2 Lab1 Lab3 *.a *.o *.so 

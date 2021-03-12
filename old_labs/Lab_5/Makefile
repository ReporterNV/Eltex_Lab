indent: *.c
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux *.c	

Lab1 libstat.a: ./Source/Lab1.c
	gcc -c ./Source/Lab1.c -o Lab.o && ar rc libstat.a Lab.o && ranlib libstat.a 

Lab2: ./Source/Lab2.c libstat.a 
	gcc ./Source/Lab2.c -lstat -L. -std=c99 -o Lab2  

Lab2test: 
	./Lab2 

Lab3: ./Source/Lab1.c ./Source/Lab2.c 
	gcc -fPIC -shared  ./Source/Lab1.c -o libDLL.so && gcc ./Source/Lab2.c -o Lab3 -L. -lDLL -Wl,-rpath,. 

Lab3test:
	./Lab3	

Lab4: ./Source/Lab3.c ./Source/Lab4.c 
	gcc -shared -o libDLL.so -fPIC ./Source/Lab1.c && gcc ./Source/Lab4.c -o Lab4 -ldl 

Lab4test: Lab4
	./Lab4	

clear: 
	rm Lab2 Lab1 Lab3 Lab4 *.a *.o *.so 

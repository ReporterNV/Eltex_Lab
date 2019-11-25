indent: *.c
	indent -kr -i8 -ts8 -l80 -sob -ss -bs-linux *.c	
Lab: Lab.c 
	gcc -Wall -g -std=c99 Lab.c -o Lab && ./Lab custom.txt 2 
client: client.c msgq.h
	gcc client.c -o client 
sever: sever.c msgq.h
	gcc server.c -o server 
clean: 
	rm server client 

indent: *.c
	indent -kr -i8 -ts8 -l180 -sob -ss -bs-linux *.c	
Lab: Lab.c 
	gcc -Wall -g -std=gnu99 Lab.c -o Lab 
client: client.c msgq.h
	gcc client.c -o client 
sever: sever.c msgq.h
	gcc server.c -o server 
clear: 
	rm Lab 

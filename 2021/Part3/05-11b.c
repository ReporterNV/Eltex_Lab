#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	printf("HELLO");
	if (argc != 2) {
		printf("Wrong arg\n");
		exit(-1);
	}
char str[10];
//	printf("%s\n", argv[0]);
//	printf("%s\n", argv[1]);

	int size = read((int)argv[1],"Hello", 10);
	if(size < 6)
		fprintf(stderr, "Possible error\n");
	
	printf("Prog2 finished work");

	return 0;
}

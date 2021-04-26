#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
printf("Hello world\n");


for (int i = 0; i< 4; i++)
	printf("%d\n", *argv[i]);		
printf("%d:%d\n", argv[1],argv[2]);
return 0;
}

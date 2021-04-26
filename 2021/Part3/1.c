#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>

int main()
{

	int fd[2];
	if (pipe(fd) < 0) {
		printf("Cannot create pipe\n");
		return 1;
	}
	pipe(fd);
	int a = 9;
	char *b = (char*)&a; 
	printf("%d:%d\n", fd[0], fd[1]);
	if( execl("prog1", "", (int*)b, (int*)&fd[0], (int*)&fd[1], NULL) < 0)
		printf("Cannot call programm\n");
	printf("Error: %s\n", strerror(errno));
	printf("NOOOOOO");
	execlp("ls", "", NULL);
	return 0;
}

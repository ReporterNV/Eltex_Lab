#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main()
{

	int fd[2];

	if (pipe(fd) < 0) {
		fprintf(stderr, "Cannot create pipe\n");
		return 0;
	}

	int pid = fork();

	if (pid < 0) {
		printf("Cannot create fork\n");
		exit(-1);
	} else if (pid > 0) {

		pid = fork();
		if (pid < 0) {
			printf("Cannot create fork\n");
			exit(-1);
		} else if (pid > 0) {
			wait(NULL);
			wait(NULL);
			close(fd[0]);
			close(fd[1]);

			return 0;
		} else {
			execl("prog2", fd[0], NULL);
		}

	} else {

		execl("prog1", fd[1], NULL);
	}

	//execl("hello", "", "str", NULL);
	//execl("/usr/bin/ls", "", NULL);
	//execl("prog2", fd[1], NULL);

}

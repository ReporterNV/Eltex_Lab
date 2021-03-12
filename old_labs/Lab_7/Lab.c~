#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<wait.h>
#include<sys/stat.h>
#include<sys/stat.h>
#define MAX_SIZE 1024

int main(int argc, char *argv[])
{
	printf("Enter matrix size: ");
	int size = 0;
	if ((scanf("%d", &size) != 1) || (size > MAX_SIZE) || (size < 0)) {
		fprintf(stderr, "Uncorect size\n");
		return -1;
	}
	int *start = 0;
	start = (int *) calloc(size * size, sizeof (int));
	int max_matrix = size * size;
	printf("Enter the matrix:\n");
	for (int i = 0; i < max_matrix; i++)
		scanf("%d", &start[i]);

	int *vector = 0;
	vector = (int *) calloc(size, sizeof (int));
	printf("Enter the vector:\n");
	for (int j = 0; j < size; j++)
		scanf("%d", &vector[j]);
////////////////////////////
	int pid[size], status, stat;

	int fd[size][2];
	for (int i = 0; i < size; i++) {
		pipe(fd[i]);
		pid[i] = fork();

		if (-1 == pid[i]) {
			perror("fork");
			exit(1);
		} else if (0 == pid[i]) {

			close(fd[i][0]);

			int result = 0;
			for (int j = 0; j < size; j++)
				result += start[i * size + j] * vector[j];
			write(fd[i][1], &result, sizeof (int));
			exit(0);
		}
	}

	for (int i = 0; i < size; i++) {
		status = waitpid(pid[i], &stat, 0);
		if (pid[i] == status) {
			printf("Child %d done\n", i);
			close(fd[i][1]);
			int len;
			read(fd[i][0], &len, sizeof (int));
			printf("i=%d len=%d\n", i, len);
			vector[i] = len;
		}
	}

	printf("Final matrix:\n");

	for (int i = 0; i < size; i++) {
		printf("%d", vector[i]);
		puts("");
	}

	return 0;
}

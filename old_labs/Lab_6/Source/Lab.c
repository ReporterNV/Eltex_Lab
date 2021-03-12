#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<wait.h>
#include<sys/stat.h>
#include<sys/stat.h>
#define MAX_LENGTH 256
#define MAX_STRING 256

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Use: programm text.txt\n");
		return -1;
	}

	char a[MAX_LENGTH] = { 0 };
	char buff[MAX_LENGTH] = { 0 };
	char search[MAX_LENGTH] = { 0 };

	FILE *file;
	if ((file = fopen(argv[1], "r")) == NULL) {
		printf("Cannot open this file\n");
		return -2;
	}
	printf("Enter searchable: ");

	scanf("%255s", search);
	printf("search:%s\n", search);
	pid_t pid[MAX_STRING];
	int i = 0;

	while ((fgets(buff, MAX_LENGTH, file)) != NULL) {

		pid[i] = fork();
		if (pid[i] < 0) {	//error
			printf("PID ERROR");
			return -3;
		} else if (pid[i] == 0) {	//child
			printf("Child process #%lu start work\n", getpid());
			if ((strstr(buff, search) > 0))
				return 1;
			else
				return 0;
		}
		i++;
	}

	int stat = 0;
	int status = 0;

	for (int j = 0; j < i; j++) {
		status = waitpid(pid[j], &stat, 0);
		if (status == pid[j]) {
			if (WEXITSTATUS(stat) == 0)
				printf
				    ("In line #%d could not find str. PID: %lu\n",
				     j + 1, pid[j]);
			if (WEXITSTATUS(stat) == 1)
				printf("In line #%d finded str. PID: %lu\n",
				       j + 1, pid[j]);
			if (WEXITSTATUS(stat) == -3) {
				printf("Cannot create process\n");
			}
		}
	}

	fclose(file);
	return 0;
}

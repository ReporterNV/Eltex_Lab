#include "includes.h"

int main(int argc, char *argv[]) {

	signal(SIGINT, close_function);

	key_t key = ftok(".", 'S');
	printf("\nKEY: %d\n", key);


	if ((msqid = msgget(key, MSGPERM | IPC_CREAT | IPC_EXCL)) < 0) {
		fprintf(stderr, "\nERROR: cannot create message queue.\n");
		return -1;
	}
	fprintf(stderr, "\nMessage queue was created\n");



	printf("\nEnter number of threads:");
	int threads = 0;
	if ((scanf("%d", &threads) != 1) || (threads <= 0) || (threads > MAX_THREADS)) {
		fprintf(stderr, "Uncorect size\n");
		if (msgctl(msqid, IPC_RMID, NULL)) {
			perror(strerror(errno));
			return -2;
		}
		return -1;
	}

if(msqid == 0){
	return 0;}
	
	printf("Enter min: ");
	int min = 0;
	if ((scanf("%d", &min) != 1) || (min > MAX_SIZE) || (min < 0)) {
		fprintf(stderr, "Uncorect size\n");
		if (msgctl(msqid, IPC_RMID, NULL)) {
			perror(strerror(errno));
			return -2;
		}
		return -1;
	}

if(msqid == 0){
	return 0;}
	
	printf("Enter max: ");
	int max = 0;
	if ((scanf("%d", &max) != 1) || (max > MAX_SIZE) || (max < min)) {
		fprintf(stderr, "Uncorect size\n");
		if (msgctl(msqid, IPC_RMID, NULL)) {
			perror(strerror(errno));
			return -2;
		}
		return -1;
	}

if(msqid == 0){
	return 0;}
	
	int mod = (max - min + 1) % threads;
	int step = (max - min + 1 - mod) / threads;

	pid_t pid[MAX_THREADS];

	if (threads > (max - min)) {
		for (int i = min; i <= max; i++) {
			pid[i] = fork();
			if (pid[i] == 0) {
				if (child_function(i, i, msqid)) {
					fprintf(stderr, "\nERROR\n");
					return -3;
				}
				return 0;
			}
		}
	} else {
		for (int i = min; i < max; i += step) {

			if ((i + step + mod - 1) < max) {
				pid[i] = fork();
				if (pid[i] == 0) {
					if (child_function(i, i + step - 1, msqid)) {
						fprintf(stderr, "\nERROR\n");
						return -3;
					}
					return 0;
				}
			} else {
				pid[i] = fork();
				if (pid[i] == 0) {
					if (child_function(i, max, msqid)) {
						fprintf(stderr, "\nERROR\n");
						return -3;
					}
					return 0;
				}
				break;
			}
		}

	}

	int stat = 0;
	int status = 0;

	for (int j = min; j <= max; j++) {
		status = waitpid(pid[j], &stat, 0);
		if (status == pid[j])
			if (WEXITSTATUS(stat) == -3)
				fprintf(stderr, "PROCESS ERROR\n");

	}

	struct msg_buf MSG = { 1, 0 };

	while (msgrcv(msqid, &MSG, sizeof(msg) - sizeof(long), -100, IPC_NOWAIT) > 0)
		printf("\nFound a prime number: %li.\n", MSG.mtext);

	if (msgctl(msqid, IPC_RMID, NULL)) {
		perror(strerror(errno));
		return -2;
	}

	fprintf(stderr, "\nMessage queue closed\n");
	return 0;
}

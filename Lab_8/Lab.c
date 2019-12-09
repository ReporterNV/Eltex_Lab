#include"msgq.h"

int function(int a, int b)
{
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int SimpleCheck(int a)
{
	for (int i = 2; i < a; i++) {
		int p = function(i, a);
		if ((p != a) && (p != 1))
			return 0;
	}
	return a;
}

int main(int argc, char *argv[])
{

	key_t key = ftok(".", 'S');
	printf("\nKEY: %d\n", key);

	struct msg_buf MSG = { 1, 0 };
	int msqid;
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

	int mod = (max - min) % threads;

	pid_t pid[MAX_THREADS];

	if ((max - min) <= threads) {
		for (int i = min; i <= max; i++) {
			pid[i] = fork();

			if (pid[i] < 0) {	//error
				printf("PID ERROR");
				return -3;
			} else if (pid[i] == 0) {	//child
				if (SimpleCheck(i) != 0) {
					printf("Process №%d find a simple number: %d\n", getpid(), i);
					MSG.mtext = i;

					if (msgsnd(msqid, &MSG, sizeof (msg) - sizeof (long), IPC_NOWAIT)) {
						perror(strerror(errno));
						return -2;
					}

				}
				exit(0);
			}
		}

	} else {
		for (int i = min; i <= max - mod; i += threads - 1) {
			pid[i] = fork();

			if (pid[i] < 0) {	//error
				printf("PID ERROR");
				return -3;
			} else if (pid[i] == 0) {	//child

				if (i + threads + mod < max) {
					max = i + threads - 1;
					for (int j = i; j < max; j++) {
						if (SimpleCheck(j) != 0) {
							printf("\nProcess №%d find a simple number: %d\n", getpid(), j);
							MSG.mtext = i;

							if (msgsnd(msqid, &MSG, sizeof (msg) - sizeof (long), IPC_NOWAIT)) {
								perror(strerror(errno));
								return -2;
							}
							return 0;
						}
					}
				}

			}
		}
	}

	int stat = 0;
	int status = 0;

	for (int j = min; j <= max; j++) {
		status = waitpid(pid[j], &stat, 0);
		if (status == pid[j]) {
			if (WEXITSTATUS(stat) == -3) {
				fprintf(stderr, "Cannot create process\n");
			}
			//if (WEXITSTATUS(stat) == 0)
			//      printf("\n Process №%d done successful\n", pid[j]);
		}
	}

	while (msgrcv(msqid, &MSG, sizeof (msg) - sizeof (long), -100, IPC_NOWAIT) > 0)
		printf("\nFinded simple number: %li.\n", MSG.mtext);
	if (msgctl(msqid, IPC_RMID, NULL)) {
		perror(strerror(errno));
		return -2;
	}

	fprintf(stderr, "\nMessage queue closed\n");
	return 0;
}

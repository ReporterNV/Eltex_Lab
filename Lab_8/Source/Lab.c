#include"msgq.h"

int function(int a, int b) {
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int prime_check(int a) {
	for (int i = 2; i < a; i++) {
		int p = function(i, a);
		if ((p != a) && (p != 1))
			return 0;
	}
	return a;
}

int child_function(int a, int b, int msqid) {

	struct msg_buf MSG = { 1, 0 };
	for (int i = a; i <= b; i++) {
		if (prime_check(i)) {
			MSG.mtext = i;
			if (msgsnd(msqid, &MSG, sizeof(msg) - sizeof(long), IPC_NOWAIT)) {
				perror(strerror(errno));
				return -3;
			}
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {

	key_t key = ftok(".", 'S');
	printf("\nKEY: %d\n", key);

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

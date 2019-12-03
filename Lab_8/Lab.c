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

	int msqid;
	if ((msqid = msgget(key, MSGPERM | IPC_CREAT | IPC_EXCL)) < 0) {
		fprintf(stderr, "\n(Server)ERROR: cannot create message queue.\n");
		return -1;
	}

	fprintf(stderr, "\nMessage queue was created\n");

	printf("\nEnter number threads:");
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

	int i = 0;

/*	for (i; i < (threads); i++) {
		printf("\n%d-%d\n", x + (y - x) / (threads) * (i), x + (y - x) / (threads) * (i + 1) - 1);
	}
	if ((x + (y - x) / (threads * threads) - 1) != y)
		printf("\n%d-%d\n", x + (y - x) / (threads) * (threads), y);
*/

	pid_t pid[MAX_THREADS];
	i = 0;
	if ((max - min) < threads)
		for (int j = min; j <= max; j++) {
			pid[j] = fork();
			if (pid[j] < 0) {	//error
				printf("PID ERROR");
				return -3;
			} else if (pid[j] == 0) {	//child
				printf("Child process #%i start work\n", getpid());
				return SimpleCheck(j);
			}
			i++;
		}
/*	else
		for() 
*/		

//TAKE RESULTS
	int stat = 0;
	int status = 0;
	printf("Simple numbers: ");
	for (int j = min; j <= max; j++) {
		status = waitpid(pid[j], &stat, 0);
		if (status == pid[j]) {
			if (WEXITSTATUS(stat) == -3) {
				fprintf(stderr, "Cannot create process\n");
			}
			if(WEXITSTATUS(stat) != 0)
			printf("%d ", WEXITSTATUS(stat));
			//printf("Return: #%d str. PID: %lu\n", WEXITSTATUS(stat), pid[j]);
		}
	}
	puts("\n");
	if (msgctl(msqid, IPC_RMID, NULL)) {
		perror(strerror(errno));
		return -2;
	}

	fprintf(stderr, "\n(Server)Message queue closed\n");
	return 0;
}

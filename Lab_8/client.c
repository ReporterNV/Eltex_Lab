#include"msgq.h"
int main(int argc, char *argv[])
{
	int msqid;

	key_t key = ftok("./server.c", 'S');
//      printf("\nKEY: %d\n", key);

	if ((msqid = msgget(key, MSGPERM)) < 0) {
		fprintf(stderr, "ERROR: cannot open message queue.\n");
		return -1;
	}
	printf("\n\t(Client)Connected is correct.\n");
	printf("\n\t(Client)Enter 0 for help\n");

	_Bool flag = 0;
	int x = 0;

	struct msg_buf MSG = { 1, x };

	while (x > -1) {
		printf("\n\t(Client)Enter number: ");
		scanf("%i", &x);

		if (x > 0) {

			MSG.mtext = x;

			if (msgsnd
			    (msqid, &MSG, sizeof (msg) - sizeof (long),
			     IPC_NOWAIT)) {
				perror(strerror(errno));
				return -2;
			}

			printf("\n\t(Client)Message sended\n");

			if (flag) {
				msgrcv(msqid, &MSG,
				       sizeof (msg) - sizeof (long), 1, 0);
				printf("\nRESULT: %d\n", MSG.mtext);
				flag = 0;
			} else {
				flag++;
			}
		} else if (x < 0) {
			MSG.mtext = -1;
			if (msgsnd
			    (msqid, &MSG, sizeof (msg) - sizeof (long),
			     IPC_NOWAIT)) {
				perror(strerror(errno));
				return -2;
			} else {
				printf("\n\t(Client)Close message sended\n");
			}
		} else {
			printf("\n\t(Client)Enter number for calculation;");
			printf("\n\t(Client)Enter 0 for help;");
			printf("\n\t(Client)Enter -1 for exit;\n\n");
		}
	}

	printf("\n\t(Client)My job is done. Bye.\n");
	return 0;
}

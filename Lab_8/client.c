#include"msgq.h"

int main(int argc, char *argv[]){
	
	key_t key = ftok("./Lab.c", 'M');
	printf("\nKEY: %d\n", key);
	
	int msqid;
	if ((msqid = msgget(key, MSGPERM )) < 0) {
		fprintf(stderr, "ERROR: cannot open message queue.\n");
		return -1;
	}

	printf("Connected is correct.\n");

	struct msg_buf MSG;
/*
	int send = msgsnd(msqid, &MSG, sizeof (msg) - sizeof (long), IPC_NOWAIT);
	if (send < 0) {
		perror(strerror(errno));
		return -2;
	} else {
		printf("Message sended\n");
	}
*/
	msgrcv(msqid, &MSG, sizeof (msg) - sizeof (long), 0, IPC_NOWAIT);
	printf("TAKED MSG: %s\n", MSG.mtext);

	if (msgctl(msqid, IPC_RMID, NULL)) {
		perror(strerror(errno));
		return 1;
	}

	printf("message queue %d is gone\n", msqid);
	return 0;
}

#include"msgq.h"
int main(int argc, char *argv[])
{
//	struct msqid_ds info;
	int msqid;
	
	key_t key = ftok("./Lab.c", 'M');
	printf("\nKEY: %d\n", key);
	
	if ((msqid = msgget(key, MSGPERM | IPC_CREAT | IPC_EXCL)) < 0) {
		fprintf(stderr, "ERROR: cannot create message queue.\n");
		return -1;
	}
	printf("\nMS Q created\n");
	struct msg_buf mymassage = { 1, "TEST" };
	struct msg_buf MSG;
	printf("N:%d; MSG:%s\n", mymassage.mtype, mymassage.mtext);

	int send = msgsnd(msqid, &mymassage, sizeof (msg) - sizeof (long), IPC_NOWAIT);
	if (send < 0) {
		perror(strerror(errno));
		return -2;
	} else {
		printf("Message sended\n");
	}

	msgrcv(msqid, &MSG, 1, MSG.mtype, IPC_NOWAIT);
	printf("TAKED MSG: %s\n", MSG.mtext);

	send = msgctl(msqid, IPC_RMID, NULL);
	if (send < 0) {
		perror(strerror(errno));
		printf("msgctl (return queue) failed, ID: %d\n", send);
		return 1;
	}

	printf("message queue %d is gone\n", msqid);
	return 0;
}

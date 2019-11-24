#include"msgq.h"
int main(int argc, char *argv[])
{
	int msqid;
	
	key_t key = ftok("./Lab.c", 'M');
	printf("\nKEY: %d\n", key);
	
	if ((msqid = msgget(key, MSGPERM | IPC_CREAT | IPC_EXCL)) < 0) {
		fprintf(stderr, "ERROR: cannot create message queue.\n");
		return -1;
	}
	printf("\nMessage queue created\n");
	struct msg_buf MyMSG= { 1, "TEST" };
	
	
	if (msgsnd(msqid, &MyMSG, sizeof (msg) - sizeof (long), IPC_NOWAIT)) {
		perror(strerror(errno));
		return -2;
	} else {
		printf("Message sended\n");
	}
	
	printf("My job is done. Bye.\n");
/*
	msgrcv(msqid, &MyMSG, 1, MyMSG.mtype, IPC_NOWAIT);
	printf("TAKED MSG: %s\n", MyMSG.mtext);

	
	if (msgctl(msqid, IPC_RMID, NULL)) {
		perror(strerror(errno));
		return -3;
	}

	printf("message queue %d is gone\n", msqid);
*/	return 0;
}

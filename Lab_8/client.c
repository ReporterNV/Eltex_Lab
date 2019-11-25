#include"msgq.h"
int main(int argc, char *argv[])
{
	int msqid;
	
	key_t key = ftok("./server.c", 'S');
	printf("\nKEY: %d\n", key);
	
	if ((msqid = msgget(key, MSGPERM )) < 0) {
		fprintf(stderr, "ERROR: cannot open message queue.\n");
		return -1;
	}
	printf("Connected is correct.\n");
	//int x= 0;
	//printf("Enter number: %d", &x);	
	
	struct msg_buf MyMSG1 = { 1, "1" };
	struct msg_buf MyMSG2 = { 1, "2" };
	struct msg_buf MyMSG3 = { 1, "0" };
	struct msg_buf MyMSG4 = { 1, "-1"};
	
	
	if (msgsnd(msqid, &MyMSG1, sizeof (msg) - sizeof (long), IPC_NOWAIT)) {
		perror(strerror(errno));
		return -2;
	} else {
		printf("Message sended\n");
	}
	
	if (msgsnd(msqid, &MyMSG2, sizeof (msg) - sizeof (long), IPC_NOWAIT)) {
		perror(strerror(errno));
		return -2;
	} else {
		printf("Message sended\n");
	}
	sleep(:);
	if (msgsnd(msqid, &MyMSG3, sizeof (msg) - sizeof (long), IPC_NOWAIT)) {
		perror(strerror(errno));
		return -2;
	} else {
		printf("Message sended\n");
	}

	if (msgsnd(msqid, &MyMSG4, sizeof (msg) - sizeof (long), IPC_NOWAIT)) {
		perror(strerror(errno));
		return -2;
	} else {
		printf("Message sended\n");
	}

	printf("My job is done. Bye.\n");
	return 0;
}

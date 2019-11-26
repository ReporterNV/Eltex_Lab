#include"msgq.h"
int main(int argc, char *argv[])
{
	int msqid;
	
	key_t key = ftok("./server.c", 'S');
//	printf("\nKEY: %d\n", key);
	
	if ((msqid = msgget(key, MSGPERM )) < 0) {
		fprintf(stderr, "ERROR: cannot open message queue.\n");
		return -1;
	}
	printf("\n\t(Client)Connected is correct.\n");
	printf("\n\t(Client)Enter 0 for help\n");	
	
	int x = 0;
	while(x > -1){	
	printf("Enter number: ");	
	scanf("%i", &x);	
		
	if(x > 0){	
		struct msg_buf MyMSG = { 1, x };
			
		if (msgsnd(msqid, &MyMSG, sizeof (msg) - sizeof (long), IPC_NOWAIT)) {
			perror(strerror(errno));
			return -2;
		} else {
			printf("\n\t(Client)Message sended\n");
		}
	}else
		if(x < 0){
			struct msg_buf MyMSG = { 1, -1 };
			if (msgsnd(msqid, &MyMSG, sizeof (msg) - sizeof (long), IPC_NOWAIT)) {
				perror(strerror(errno));
				return -2;
			} else {
				printf("\n\t(Client)Close message sended\n");
			}
		}else{
			puts("\n\t(Client)Enter number for calculation;");
			puts("(Client)Enter 0 for help;");
			puts("(Client)Enter -1 for exit;");}
	}

	printf("(Client)My job is done. Bye.\n");
	return 0;
}

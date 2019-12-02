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

int CreateMessageQueue(key_t key){
int msqid;
	if ((msqid = msgget(key, MSGPERM | IPC_CREAT | IPC_EXCL)) < 0) {
		fprintf(stderr,
			"\n(Server)ERROR: cannot create message queue.\n");
		return -1;
	}
	fprintf(stderr, "\n(Server)Message queue created\n");

return msqid;
}

int main(int argc, char *argv[]){

	key_t key = ftok("./server.c", 'S');
	printf("\nKEY: %d\n", key);

	int msqid = CreateMessageQueue(key);
	if(msqid == -1)
		return -1;

	int x = 0;
	int y = 0;

	struct msg_buf MSG;

	while (1) {
		msgrcv(msqid, &MSG, sizeof (msg) - sizeof (long), 0, 0);
		x = MSG.mtext;
		fprintf(stderr, "(Server)Take:%d\n", x);
	
		if (x < 0) {
			fprintf(stdin, "\n(Server)Received exit message\n");
			if (msgctl(msqid, IPC_RMID, NULL)) {
				perror(strerror(errno));
				fprintf(stderr,"\nServer closed without remove queue.\n");
				return -2;
			}

			fprintf(stdin, "\n(Server)Message queue was closed\n");
			return 0;

		} else {
			if (y) {
				//send result;
				MSG.mtext = function(x, y);
				if (msgsnd(msqid, &MSG, sizeof (msg) - sizeof (long), IPC_NOWAIT))
					fprintf(stderr,	"\nERROR: cannot send message with result\n");

				printf("\n\n(Server)RESULT: %d\n\n",
				       function(x, y));
				x = 0;	y = 0;
			}else{
			y = x;
			}
		}
	}
	printf("It's something strange.\nServer will be closed.\n");
	return 0;
}

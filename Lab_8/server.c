#include"msgq.h"

int function(int a, int b){
while(a != b){
	if(a > b)
		a = a - b;
	else 
		b = b - a; 
}

return a;
}

int main(int argc, char *argv[]){
	
	key_t key = ftok("./server.c", 'S');
	printf("\nKEY: %d\n", key);
	
	int msqid;

	//if ((msqid = msgget(key, MSGPERM | IPC_CREAT | IPC_EXCL)) < 0) {
	if ((msqid = msgget(key, MSGPERM | IPC_CREAT )) < 0) {
		fprintf(stderr, "ERROR: cannot create message queue.\n");
		return -1;
	}
	fprintf(stderr,"\nMessage queue created\n");

	int x = 0;
	int y = 0;
	
	struct msg_buf MSG;
	while(1){
	msgrcv(msqid, &MSG, sizeof (msg) - sizeof (long), 0, 0);
	x = atoi(MSG.mtext);
	fprintf(stderr, "Take:%d\n", x );
	if(x < 0){
	fprintf(stderr, "Received exit message\n");
		if (msgctl(msqid, IPC_RMID, NULL)) {
			perror(strerror(errno));
			return -2; }
	fprintf(stderr, "Message queue closed\n");
	return 0;
	}else{
		if(y == 0){
			y = x;
		}else{
			//send result;
			printf("RESULT: %d", function(x,y));
			x = 0; y = 0;
			}	
		}
	}
	printf("It's something strange.\nServer will be closed.\n");
	return 0;
}

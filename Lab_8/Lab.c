#include"msgq.h"
int main(int argc, char *argv[])
{
	int msqid, key;
	if((msqid = msgget(IPC_PRIVATE, IPC_CREAT | IPC_EXCL))<0){
		printf(stderr, "ERROR: cannot create message queue.\n");
		return -1;
	}
	
	msg mymassage = {1, "TEST"};

	if(msgsnd(msqid, &mymassage, ,IPC_NOWAIT))
	

	return 0;
}

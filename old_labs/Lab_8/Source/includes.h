
#include<time.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<wait.h>
#include<sys/stat.h>
#include <signal.h> 
#define MAX_SIZE 1024
#define MAX_THREADS 1024
#define MSGPERM 0600		// msg queue permission
#define MSGTXTLEN 128		// msg text length
#define MSGKEY 32769

int msqid = 0;

struct msg_buf {
	long mtype;
	long mtext;
} msg;


int function(int a, int b) {
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int prime_check(int a) {
	for (int i = 2; i < a; i++) {
		int p = function(i, a);
		if ((p != a) && (p != 1))
			return 0;
	}
	return a;
}

int child_function(int a, int b, int msqid) {

	struct msg_buf MSG = { 1, 0 };
	for (int i = a; i <= b; i++) {
		if (prime_check(i)) {
			MSG.mtext = i;
			if (msgsnd(msqid, &MSG, sizeof(msg) - sizeof(long), IPC_NOWAIT)) {
				perror(strerror(errno));
				return -3;
			}
		}
	}
	return 0;
}

void close_function(int sig){
fprintf(stderr, "\nClosing message queue\n");	
	if (msgctl(msqid, IPC_RMID, NULL))
		perror(strerror(errno));
	msqid = 0;
	exit(0);
}


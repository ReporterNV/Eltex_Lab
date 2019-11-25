
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
#include<sys/stat.h>
#define MAX_SIZE 1024


#define MSGPERM 0600		// msg queue permission
#define MSGTXTLEN 128		// msg text length
#define MSGKEY 32769
struct msg_buf
{
  long mtype;
  long mtext;
} msg;

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<wait.h>
#include<sys/stat.h>
#include<sys/stat.h>
#define MAX_LENGTH 256

int main(int argc, char *argv[]){
if(argc!=2){
printf("Use: programm text.txt\n");
return -1;
}

char a[MAX_LENGTH] = {0};
char buff[MAX_LENGTH]={0};
char search[MAX_LENGTH]={0};

FILE *file;
if((file = fopen(argv[1],"r")) == NULL){
printf("Cannot open this file\n");
return -2;
}
printf("%d_\n", scanf("%254s", search));
printf("%s", search);

while(fscanf("%s", buff) == NULL)

fclose(file);
return 0;
}

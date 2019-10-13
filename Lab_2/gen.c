#include<stdio.h>
#include<stdlib.h>

void main(int argc, char *argv[]){

unsigned int num = rand()%100+2;
 
if(argc>1)
	num = atoi(argv[1]);
FILE *file = fopen("custom.txt", "w");
fprintf(file, "%u\n", num);

for(unsigned i=0;i<num;i++){
int k = rand()%20+2;
	for(int j=0;j<k;j++){ // gen str
		char ch  = rand()%42+48;
	while((ch>57)&&(ch<65))
		ch  = rand()%42+48;
		fprintf(file, "%c", rand()%42+48);
	}
	fprintf(file,"\n");
}

fclose(file);
}

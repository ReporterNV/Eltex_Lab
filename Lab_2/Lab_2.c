#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 1024

static unsigned int N = 0;
static unsigned int counter = 0;

int inp_str(char **p){

printf("\n Enter number of strings: ");
scanf("%u", &N);

int inp_str(char **p){

printf("\n Enter number of strings: ");
scanf("%u", &N);
if(!N){
return 1;
}
p = (char **)calloc(N, sizeof(char *));

char buff[MAX_LEN];

for (int i = 0; i < N; i++){
	scanf("%s", buff);
	p[i] = (char*)malloc(sizeof(char)*strlen(buff));

	strcpy(p[i], buff);
printf("%s\n", p[i]);
	}
return 0;
}

void out_str(char **p){
for(int i = 0; i < N; i++)
	printf("%s\n", mass[i]);
}


int fsort(char *a, char *b){

return a-b ;
} 
int main(){

char **mass = NULL; 

if(inp_str(mass)){
puts("ERROR");
}

qsort();

printf("OUTPUT:\n");

out_str(mass);

return 0;

}

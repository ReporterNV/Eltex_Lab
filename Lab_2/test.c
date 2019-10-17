#include<stdio.h>
#include<stdlib.h>

void main(){

int **a = NULL;
a  = (int**)calloc(10, sizeof(int* ));

for(int i=0;i<10;i++){
	a[i] =(int *) malloc(sizeof(int)*10);
	for(int j = 0;j<10 ;j++)
	a[i][j]  = i+j;
	
}
for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
		if(a[0][0]+j+i  != i+j)
		printf("DONT WORK");	
printf("WORK");
}

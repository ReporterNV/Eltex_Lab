#include <stdio.h>
#include <stdlib.h>
/*
typedef struct Note{
char *note 
unsigned int numbers;
struct Note *next;

}Note;


void inp_str(){
}


void out_str(){
}

*/
int main(){

unsigned int N = 0;

printf("\n Enter number of strings: ");
scanf("%u", &N);

if(N>0)

printf("%d\n", N);
char *mass = malloc(sizeof(char[255])*N );

for(int i = 0; i < N; i++)
scanf("%s", &mass[i]);

for(int i = 0; i < N; i++)
printf("%s", (char*)mass[i]);

return 0;
}

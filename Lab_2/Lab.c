#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 1024

static int N = 0;
static unsigned int counter = 0;


char ***mass = NULL;

int num_in_str(char *p)
{
    int num_in_ln = 0;
    unsigned short str_len = strlen(p);
    for (int i = 0; i < str_len; i++)
	if((p[i]<='9')&&(p[i]>='0'))	
		num_in_ln++;
return num_in_ln;
}

void input()
{
    printf("\n Enter number of strings: ");
    scanf("%u", &N);

    if (abs(!N)) {
	fprintf(stderr,"\nNo lines\n");
}
puts("");
	mass = (char ***)calloc(N, sizeof(char**));
    
    char buff[MAX_LEN];

    for (int i = 0; i < N; i++) {
	scanf("%s", buff);

	mass[i] = (char **)calloc(2, sizeof(char*));
	
	mass[i][0] = (char *) malloc(sizeof (char) * strlen(buff));
	strcpy(mass[i][0], buff);
        mass[i][1]= (char*)malloc(sizeof(char));	
	sprintf(mass[i][1], "%d", num_in_str(buff));
    
   
    }

}

void output() {
	for (int i = 0; i < N; i++)
	   printf("%s:%s\n", mass[i][0], mass[i][1]);
}

int fsort(const void *a, const void *b) {
register char** el1 = *(char ***)a;
register char** el2 = *(char ***)b;
	
	printf("\n%d(%c):%d(%c)\n", el1[1][0], el1[1][0], el2[1][0], el2[1][0]);
if( strcmp(( el1[1] ), (el2[1])) < 0) {//What do you think about rewrite this?

	counter++;
	    return 1;
	}
	else 
	return -1;
    }

void free_all(){

    for (int i = 0; i < N; i++) {
	 free(mass[i][0]);
	 free(mass[i][1]);

free(mass[i]);
}

}


int main(int agvc, char *argv[]) {
input();

qsort(mass, N, sizeof(char **), fsort);
	
output();
printf("\nPermutation: %d\n", counter);
	free_all();	
	free(mass);
	return 0;
 }

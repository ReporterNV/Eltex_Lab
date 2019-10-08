#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 1024

static int N = 0;
static unsigned int counter = 0;

int num_in_str(char *p)
{
    int num_in_ln = 0;
    unsigned short str_len = strlen(p);
    for (int i = 0; i < str_len; i++)
	if((p[i]<='9')&&(p[i]>='0'))	
		num_in_ln++;
return num_in_ln;
}

char **inp_str(char **p)
{
    printf("\n Enter number of strings: ");
    scanf("%u", &N);

    if (abs(!N)) {
	printf("\nNo lines\n");
	return 0;
    }

    p = (char **) calloc(N, sizeof(char *));

    char buff[MAX_LEN];

    for (int i = 0; i < N; i++) {
	scanf("%s", buff);
	p[i] = (char *) malloc(sizeof (char) * strlen(buff));
	strcpy(p[i], buff);
    }

    return p;
}

void out_str(char **p) {
	for (int i = 0; i < N; i++)
	   printf("%s\n", p[i]);
}

int fsort(const void *a, const void *b) {
	if (num_in_str(*(char**)a) < num_in_str(*(char**)b)) {
	    counter++;
	    return 1;
	}
	else 
	return -1;
    }

void free_all(char **p){

    for (int i = 0; i < N; i++) {
	 free(p[i]);
free(p);
}

}

int main(int agvc, char *argv[]) {

	char **mass = NULL;
	mass = inp_str(mass);

	if (mass == 0) {
	    puts("\nERROR\n");
	    return 1;
	}
      qsort(mass, N, sizeof(char *), fsort);



	printf("OUTPUT:\n");
printf("Number of permutation: %d\n", counter);
	out_str(mass);
free_all(mass);
	return 0;
 }

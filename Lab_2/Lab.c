#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 1024

static int N = 0;
static unsigned int counter = 0;


global char ***mass = NULL;

int num_in_str(char *p)
{
    int num_in_ln = 0;
    unsigned short str_len = strlen(p);
    for (int i = 0; i < str_len; i++)
	if((p[i]<='9')&&(p[i]>='0'))	
		num_in_ln++;
return num_in_ln;
}

void inp_str()
{
    printf("\n Enter number of strings: ");
    scanf("%u", &N);

    if (abs(!N)) {
	printf("\nNo lines\n");
break();    
}

    mass = (char ***) calloc(2, sizeof(char **));
    z[0] = (char **) calloc(N, sizeof(char *));
    z[1] = (char **) calloc(N, sizeof(char *));
    
    char buff[MAX_LEN];

    for (int i = 0; i < N; i++) {
	scanf("%s", buff);
	z[0][i] = (char *) malloc(sizeof (char) * strlen(buff));
	strcpy(z[0][i], buff);
        *z[1][i]= (unsigned char)num_in_str(z[0][i]); 
}
    return z;
}

void out_str(char **p) {
	for (int i = 0; i < N; i++)
	   printf("%s\n", p[i][0]);
}

int fsort(const void *a, const void *b) {
	if( ( (char**) a ) < (char**) b) {
	    counter++;
	    return 1;
	}
	else 
	return -1;
    }

int main(int agvc, char *argv[]) {

	inp_str();

	if (mass == 0) {
	    puts("\nERROR\n");
	    return 1;
	}
      qsort(mass[0], N, sizeof(char *), fsort);

	printf("OUTPUT:\n");
	printf("Number of permutation: %d\n", counter);
	out_str(mass);

	return 0;
 }


unsigned char a = 1024;

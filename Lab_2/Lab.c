#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 1024

//static int N = 0;
//static unsigned int counter = 0;


char ***mass = NULL;
/*
int num_in_str(char *p)
{
    int num_in_ln = 0;
    unsigned short str_len = strlen(p);
    for (int i = 0; i < str_len; i++)
	if((p[i]<='9')&&(p[i]>='0'))	
		num_in_ln++;
return num_in_ln;
}
*/
void inp_str()
{
    printf("\n Enter number of strings: ");
    scanf("%u", &N);

    if (abs(!N)) {
	fprintf(stderr,"\nNo lines\n");
}

    
    char buff[MAX_LEN];

    for (int i = 0; i < N; i++) {
	scanf("%s", buff);
	z[0][i] = (char *) malloc(sizeof (char) * strlen(buff));
	strcpy(z[0][i], buff);
        *z[1][i]= (unsigned char)num_in_str(z[0][i]); 
}
    return z;
}

void output() {
	for (int i = 0; i < 2; i++)
	   printf("%s\n", mass[i][0]);
}
/*
int fsort(const void *a, const void *b) {
	if( ( (char**) a ) < (char**) b) {
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
*/
int main(int agvc, char *argv[]) {
	mass = (char ***)calloc(2, sizeof(char**));
	mass[0] = (char **)calloc(2, sizeof(char*));
	mass[1] = (char **)calloc(2, sizeof(char*));
mass[0][0] = (char*)malloc(sizeof(char)*strlen("1aaa1"));
mass[1][0] = (char*)malloc(sizeof(char)*strlen("222222b"));
strcpy( mass[0][0] , "1aaa1");
strcpy( mass[1][0] , "22222b");

mass[0][1] = (char*)malloc(sizeof(char));
sprintf(mass[0][1], "%lu", strlen("1aaa1"));
mass[1][1] = (char*)malloc(sizeof(char));
sprintf(mass[1][1], "%lu", strlen("222222b"));

printf("%s\n", mass[0][1]);
printf("%s\n", mass[1][1]);

output();

/*
if(mass[0][1][0]<mass[1][1][0])
puts("DONE");	
*/	
/*printf("%s\n", mass[1][1]);
printf("%s\n", mass[1][2]);
}*/
for(int i=0;i<2;i++){
free(mass[0][i]);
free(mass[1][i]);
}
	//rewrite to use 2 arrays
	
	free(mass);
/*	
 	inp_str();

	if (mass == 0) {
	    puts("\nERROR\n");
	    return 1;
	}

      qsort(mass[0], N, sizeof(char *), fsort);

	printf("OUTPUT:\n");
	printf("Number of permutation: %d\n", counter);
	out_str(mass);
	free_all(mass);
	free(mass);
*/
	return 0;
 }

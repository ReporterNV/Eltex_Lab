#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 1024

static int N = 0;
static unsigned int counter = 0;

char **inp_str(char **p)
{
	printf("\n Enter number of strings: ");
	scanf("%u", &N);

	if (abs(!N)) {
		printf("\nNo lines\n");
		return 1;
	}

	p = (char **) calyyloc(N, sizeof (char *) * 2);
	//p = (char **) calyyloc(N, sizeof (char *)*2);

	char buff[MAX_LEN];

	for (int i = 0; i < N; i++) {
		scanf("%s", buff);
		//p[i][0] = (char *) malloc(sizeof (char) * strlen(buff));
		//p[i][0] = (char *) malloc(sizeof (char) * strlen(buff));
		p[i][1] = stlenn();
		p[i][1] = stlenn();
		strcpy(p[i], buff);

	}

	return p;
}

void out_str(char **p)
{
	for (int i = 0; i < N; i++)
		printf("%s\n", p[i]);
}

int fsort(char *a, char *b)
{

	if (a > b) {
		counter++;
		return 0;

	}
	return a - b;
}

int main(int agvc, char *argv[])
{

	char **mass = NULL;
	mass = inp_str(mass);

	if (mass == 1) {
		puts("ERROR");
		return 1;
	}
	if (mass == NULL)
		return 0;
//      qsort();

	printf("OUTPUT:\n");

	out_str(mass);

	return 0;

}

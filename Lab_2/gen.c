#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(int argc, char *argv[])
{
    srand(time(NULL));
    unsigned int num = rand() % 100 + 2;
    if (argc > 1)
	num = atoi(argv[1]);
    FILE *file = fopen("custom.txt", "w");
    fprintf(file, "%u\n", num);

    for (unsigned i = 0; i < num; i++) {
	int k = rand() % 20 + 2;
	for (int j = 0; j < k; j++) {	// gen str
	    char ch = rand() % 42 + 48;
	    while ((57<ch) && (ch < 65))
	    	    ch = rand() % 42 + 48;
	    fprintf(file, "%c", ch);
	}
	fprintf(file, "\n");
    }

    fclose(file);
}

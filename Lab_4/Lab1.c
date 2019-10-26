#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *outname(char *inname)
{
	char *a = inname;

	if ((a = strrchr(inname, '.')) == NULL)
		strcat(inname, ".out");
	else
		strcpy(a, ".out");
	return inname;
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%d", argc);

	FILE *in = NULL;
	if (argc == 3) {
		in = fopen(argv[1], "rt");
		if (in == NULL) {
			fprintf(stderr, "Cannot open the file:%s\n", argv[1]);
			return 2;
		}
	} else {
		puts("\nIncorrect args. Use ./Lab str.txt c\n");
		return (1);
	}

	//Make this function inline
	FILE *out = NULL;

	if ((out = fopen(outname(argv[1]), "wt")) == NULL) {

		char a[255];
		fprintf(stderr,
			"\nCannot create file for write. Use stdout.\n");
		while (fscanf(in, "%s", a) > 0) {
			if (!strchr(a, argv[2][0]))
				fprintf(stdout, "%s\n", a);
		}
	} else {

		char a[255];

		while (fscanf(in, "%s", a) > 0) {
			if (!strchr(a, argv[2][0]))
				fprintf(out, "%s\n", a);
		}
	}

	//      printf("|%s|", argv[1]);
	return 0;
}

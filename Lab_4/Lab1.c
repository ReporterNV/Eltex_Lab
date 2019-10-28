#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFF_SIZE 255

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

	FILE *out = NULL;

	if ((out = fopen(outname(argv[1]), "wt")) == NULL) {

		char a[BUFF_SIZE];
		fprintf(stderr,
			"\nCannot create file for write. Use stdout.\n");
		while (fscanf(in, "%s", a) > 0) {
			if (!strchr(a, argv[2][0]))
				fprintf(stdout, "%s\n", a);
		}
	} else {

		char a[BUFF_SIZE];

		while (fscanf(in, "%s", a) > 0) {
			if (!strchr(a, argv[2][0]))
				fprintf(out, "%s\n", a);
		}
	}
fclose(in);
fclose(out);
	return 0;
}

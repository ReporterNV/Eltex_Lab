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

	char a;

	if ((out = fopen(outname(argv[1]), "wt")) == NULL) {

		fprintf(stderr,
			"\nCannot create file for write. Use stdout.\n");
		while ( (a = getc(in))!= EOF ) {
			if (a != argv[2][0])
				fprintf(stdout, "%c", a);
else 	
				fprintf(stdout, " " );	
		}
	} else {

		while ( (a = getc(in))!= EOF ) {
			if ( a != argv[2][0])
				fprintf(out, "%c", a);
else 		
				fprintf(out, " ");
}
	}
fclose(out);
fclose(in);

	return 0;
}

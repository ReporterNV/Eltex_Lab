#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{

	if (argc == 3) {
		FILE *in = NULL;
		if (in = fopen(argv[1], "rt") == NULL) {
			puts("Cannot opent the file:%s", argv[1]);
			return 2;
		} else {
			puts("\nIncorrect argsi. Use ./Lab str.txt c\n");
			return(1);
		}

char *a = NULL;
while(fscanf(in, "%s", a) != NULL){
for(int i = 0; i < strlen(a))
	if(s[i] == argv[2])
			


	}



}


}

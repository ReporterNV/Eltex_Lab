#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int fd;
	size_t size;
	char string[20];

	umask(0);

	if ((fd = open("myfile", O_RDONLY | O_EXCL, 0666)) < 0) {
		printf("Can\'t open file\n");
		exit(-1);
	}

	size = read(fd, string, 20);

	if (size != 14) {
		printf("Can\'t read all string\n");
		exit(-1);
	}
	
	printf("%s\n", string);
/* Закрываем файл */

	if (close(fd) < 0) {
		printf("Can\'t close file\n");
	}

	return 0;
}

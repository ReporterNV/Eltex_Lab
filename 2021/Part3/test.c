#include <stdio.h>
#include <unistd.h>
int main(int argc, int *argv[])
{
  printf("Будет выполнена программа %s...\n\n",
         argv[0]);
  printf("Выполняется %s", argv[0]);
  execl("/usr/bin/ls", "hello","Hello", "World!", NULL);
  return 0;
}
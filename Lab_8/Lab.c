#include"msgq.h"

int
function (int a, int b)
{
  while (a != b)
    {
      if (a > b)
	a = a - b;
      else
	b = b - a;
    }
  return a;
}

//if(a ==function(a))
//      printf("%d", a);
int
main (int argc, char *argv[])
{

  key_t key = ftok (".", 'S');
  printf ("\nKEY: %d\n", key);

  int msqid;

  if ((msqid = msgget (key, MSGPERM | IPC_CREAT | IPC_EXCL)) < 0)
    {
      fprintf (stderr, "\n(Server)ERROR: cannot create message queue.\n");
      return -1;
    }
  fprintf (stderr, "\nMessage queue create\n");

  int threads = 0;

  printf ("\nEnter number threads:");
  if ((scanf ("%d", &threads) != 1) || (threads <= 0)
      || (threads > MAX_THREADS))
    {
      fprintf (stderr, "Uncorect size\n");
      fprintf (stderr, "\n(Server)Received exit message\n");
      if (msgctl (msqid, IPC_RMID, NULL))
	{
	  perror (strerror (errno));
	  return -2;
	}
      fprintf (stderr, "\n(Server)Message queue closed\n");
      return -1;
    }

  printf ("Enter min: ");
  int x = 0;
  if ((scanf ("%d", &x) != 1) || (x > MAX_SIZE) || (x < 0))
    {
      fprintf (stderr, "Uncorect size\n");
      fprintf (stderr, "\n(Server)Received exit message\n");
      if (msgctl (msqid, IPC_RMID, NULL))
	{
	  perror (strerror (errno));
	  return -2;
	}
      fprintf (stderr, "\n(Server)Message queue closed\n");
      return -1;
    }

  printf ("Enter max: ");
  int y = 0;
  if ((scanf ("%d", &y) != 1) || (y > MAX_SIZE) || (y < 0))
    {
      fprintf (stderr, "Uncorect size\n");
      fprintf (stderr, "\n(Server)Received exit message\n");
      if (msgctl (msqid, IPC_RMID, NULL))
	{
	  perror (strerror (errno));
	  return -2;
	}
      fprintf (stderr, "\n(Server)Message queue closed\n");
      return -1;
    }

int i = 0;	
for(i;i<(threads); i++){
	printf("\n%d-%d\n", x + (y - x)/(threads) * (i), x + (y - x)/(threads) * (i+1)-1);
}
if((x+(y-x)/(threads*threads)-1) != y)
	printf("\n%d-%d\n", x+(y-x)/(threads)*(threads), y);


  pid_t pid[MAX_THREADS];
  i = 0;

  for (int j = x; j < y; j++)
    {
      pid[i] = fork ();
      if (pid[i] < 0)
	{			//error
	  printf ("PID ERROR");
	  return -3;
	}
      else if (pid[i] == 0)
	{			//child
	  printf ("Child process #%lu start work\n", getpid ());
	  //if ((strstr(buff, search) > 0))
	  return j;
	}
      i++;

    }
  
  int stat = 0;
  int status = 0;

  for (int j = x; j < y; j++)
    {
      status = waitpid (pid[j], &stat, 0);
      if (status == pid[j])
	{
	  if (WEXITSTATUS (stat) == -3)
	    {
	      printf ("Cannot create process\n");
	    }
	  printf ("Return: #%d str. PID: %lu\n", WEXITSTATUS (stat), pid[j]);
	}
    }



  fprintf (stderr, "\n(Server)Received exit message\n");
  if (msgctl (msqid, IPC_RMID, NULL))
    {
      perror (strerror (errno));
      return -2;
    }
  
  fprintf (stderr, "\n(Server)Message queue closed\n");
  return 0;
}

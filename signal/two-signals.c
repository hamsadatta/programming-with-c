#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void sighandler(int sig)
{
  static int int_counter;

  switch (sig) {
  case SIGINT:
    int_counter++;
    if (int_counter==3)
      {
        exit(0);
      }
    printf ("SIGINT (%d) pressed %d times,"
            "will print this and continue afterwards\n",
            sig, int_counter);
    break;
  case SIGHUP:
    printf ("SIGHUP (%d) pressed "
            "will print this and continue afterwards\n",
            sig);
    break;
  }
}

int
main(void)
{

  signal(SIGINT, sighandler); 
  signal(SIGHUP, sighandler); 
  
  while (1)
    {
      printf (".");
      fflush(stdout);
      usleep (100000);
    }

  return 0;
}

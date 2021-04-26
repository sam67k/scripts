#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main()
{
  int n;
  printf("please enter the number : ");
  scanf("%d", &n);
  if (n <= 0) 
    {
      printf("\nfork failed!\n");
      return 1;
    }
  pid_t pid = fork();
  if (pid == 0)
    {
      printf("fibonacci numbers up to %d : \n", n);
      int *fibarr = (int*)malloc(sizeof(int)*n);
      int i;
      for (i = 0; i < n; i++)
    {
      if (i <= 1) {
        fibarr[i] = 1;
      }
      else {
        fibarr[i] = fib_array[i-1]+fib_array[i-2];
	  }
      printf("%d \n", fibarr[i]);
    }
	exit(0);
    }
  if (pid < 0)
    {
      printf("error forking child\n");
      return 1;
    }
  if (pid > 0)
    {
      int status;
      wait(&status);
      printf("now the child process has exited with the status %d\n",  status);
      return 0;
    }
}
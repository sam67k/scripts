#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
pid_t pida, pidb;
pida = fork();
if (pida < 0 )
{
	printf("Fork failed");
	return 1;
}
else if (pida == 0){
	pidb = getpid();
	printf("A child: pida = %d\n", pida);
	printf("B child: pidb = %d\n", pidb);
}
else {
	pidb = getpid();
	printf("C parent: pida = %d\n", pida);
	printf("D parent: pida = %d\n", pidb);
	wait(NULL);
}
}

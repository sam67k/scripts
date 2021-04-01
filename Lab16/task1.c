#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void pid_value(pid_t);

int main(void) {

pid_t pid1;
pid_t pid2;
pid_t pid3;

pid1=fork();
pid_value(pid1);

pid2=fork();
pid_value(pid2);

pid3=fork();
pid_value(pid3);
}

void pid_value(pid_t pid)
{

if(pid <0)
	{
	printf("Child creation failed");
	}
else if (pid==0) {
	printf("\n child created \n ");
	}
else
{
wait(NULL);
printf("\n Child completed with parent Id \n");
}
return 1;
}

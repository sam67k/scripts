#include<pthread.h>
#include<iostream>
#include<cstdlib>

using namespace std;

int counter=0 ,next_consumed=0, next_produced=0;
int buffer[1000];
int in=0;
int out=0;
int i=0,j=0;
int BUFEER_SIZE=100;

void *producer(void *param) {
	while(i<=5) {
		while(counter == BUFEER_SIZE)
		;/* do nothing */
		buffer[in] = next_produced;
		in = (in +1) % BUFEER_SIZE;
		counter++;
		cout<<counter<<"In Produced"<<endl;
		i++;
	}
	pthread_exit(NULL);
}

void *consumer(void *param) {
	while(j<=5) {
		while(counter == 0)
		;/* do nothing */
		next_consumed = buffer[out];
		out = (out +1) % BUFEER_SIZE;
		counter--;
		cout<<counter<<"In consumer"<<endl;
		j++;
	}
	pthread_exit(NULL);
}


int main() {
	pthread_t tid,tid2;
	pthread_create(&tid,NULL,producer,(void *)NULL);
	pthread_create(&tid2,NULL,consumer,(void *)NULL);
	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);
	return 0;
}

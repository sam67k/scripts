#include<iostream>
#include<pthread.h>
#include<cstdlib>
#include<semaphore.h>

using namespace std;

int const buffersize=5;
int buffer[buffersize];
sem_t s;
int in=0, out=0;
int counter=0;
int item=5;

void *runner(void*param) {
	sem_wait(&s);
	int i=0;
	
	cout<<"Starting Thread 1...."<<endl;

	while(i<5) {
		while(counter==buffersize)
			cout<<"Starting Thread 1...."<<endl;

		while(i<5) {
			while(counter==buffersize) {
				// do nothing
			}

			buffer[in]=item;
			in =(in+1)%buffersize;
			counter++;

			cout<<"Counter in producer: "<< counter<<endl;

			i++;
		}
	}

	cout<<"Ending Thread 1"<<endl;

	sem_post(&s);
	pthread_exit(NULL);
}

void *runner1(void*param) {
	sem_wait(&s);
	int i=0;

	cout<<"Starting Thread 2...."<<endl;

	while(i<5) {
		while(counter==0) {
			// do nothing
		}
		
		item=buffer[out];
		out =(out+1)%buffersize;

		cout<<"Counter in consumer: "<<counter<<endl;
		
		counter--;
		i++;
	}


	cout<<"Ending Thread 2.... "<<endl;
	
	sem_post(&s);
	pthread_exit(NULL);
}

int main() {

	int pshared=0;
	int value=1;
	pthread_t tid, tid1;

	sem_init(&s,pshared,value);
	
	pthread_create(&tid,NULL,runner,(void*)buffer);
	pthread_join(tid,NULL);

	pthread_create(&tid1,NULL,runner1,(void*)buffer);
	pthread_join(tid1,NULL);

	pthread_exit(NULL);

	return 0;
}

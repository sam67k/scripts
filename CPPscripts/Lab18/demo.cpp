#include<iostream>
#include<pthread.h>
#include <sstream>

using namespace std;

int a=10;
int b=5;

void *add(void* param){
cout<<"Starting thread 1\n";
int c = a+b;
cout<<"a+b = "<<  c<<"\n";
cout<<"Ending thread 1\n";
pthread_exit(NULL);
}

void *sub(void* param){
cout<<"Starting thread 2\n";
int c = a-b;
cout<<"a-b = "<< c <<"\n";
cout<<"Ending thead 2\n";
pthread_exit(NULL);
}

void *mult(void* param){
cout<<"Starting thread 3\n";
int c = a*b;
cout<<"a*b = "<< c <<"\n";
cout<<"Ending thread 3\n";
pthread_exit(NULL);
}

void *sqr(void* param){
cout<<"Starting thread 4\n";
cout<<"a*a = "<< a*a <<"\n";
cout<<"b*b = "<< b*b <<"\n";
cout<<"Ending thread 4\n";
pthread_exit(NULL);
}

int main(){

pthread_t t1,t2,t3,t4;

pthread_create(&t1,NULL,add,NULL);
pthread_create(&t2,NULL,sub,NULL);
pthread_create(&t3,NULL,mult,NULL);
pthread_create(&t4,NULL,sqr,NULL);

pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);
pthread_join(t4,NULL);

return 0;
}

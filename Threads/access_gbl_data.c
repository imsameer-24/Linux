//wap to access the global dat between threads with out any synchronization?
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int g=1;
pthread_mutex_t m=PTHREAD_MUTEX_INITIALIZER;  
void* thread1(void *p)
{
	printf("Thread1 code begins..\n");
	sleep(1);
	printf("thread1 trying to apply lock\n");
	sleep(1);
	pthread_mutex_lock(&m);
	printf("thread1 applied lock\n");
	printf("in thread1 g->%d\n",g);
	sleep(20);
	printf("after delay in thread1\n");  
	printf("in thread1 g->%d\n",g);
	sleep(2);
	printf("thread1 releasing lock\n");
	sleep(2);
	pthread_mutex_unlock(&m);
	printf("lock released by thread1\n");
	sleep(1);
	printf("thread1 terminated..\n");  
}

void* thread2(void *p)
{
	printf("Thread2 code begins..\n");
	sleep(2);
	printf("thread2 trying to apply lock\n");
	sleep(2);
	pthread_mutex_lock(&m);
	printf("thread2 applied lock\n");
	printf("in thread2 g->%d\n",g);
	sleep(5);
	printf("Thread2 updating g val to 100\n");
	g=100;
	sleep(1);
	printf("in thread2 g->%d\n",g);
	sleep(2);
	printf("thread2 releasing lock\n");
	sleep(2);
	pthread_mutex_unlock(&m);
	sleep(1);
	printf("thread2 terminated..\n");
}
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t1,0,thread2,0);
	while(1);
}

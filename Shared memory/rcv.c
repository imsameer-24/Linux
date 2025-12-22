#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
int main()
{
	int id;
	char *p;
	id = shmget(5,20,IPC_CREAT|0644);
	if(id<0)
	{
		perror("shmget");
		return 0;
	}
	p=(char*)shmat(id,0,0);
	if(p==-1)
	{
		perror("shmat");
		return 0;
	}
	while(1)
	{
		printf("Message received : %s\n",p);
		sleep(2);
	}
	/*
	 while(1)
	 {
	 *p=i;
	 sleep(2);
	 i++;
	 }
	 */


	shmdt(p);
}



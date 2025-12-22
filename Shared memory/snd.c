//send data to shared memeory
#include<stdio.h>
#include<sys/shm.h>
int main()
{
	int id;
	char *p;
	id=shmget(5,20,IPC_CREAT|0644);
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
		printf("Enter message you want to send : ");
		scanf("%s\n",p);
	}
	shmdt(p);
}




#include<stdio.h>
#include<sys/msg.h>
int main()
{
	int id;
	key_t key;
	key = ftok("temp",70);
	id=msgget(key,IPC_CREAT|0644);
	//id=semget(5,3,IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	printf("Semaphore created successfully");

}

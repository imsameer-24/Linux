//Record Locking using Semaphores
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/sem.h>
int main()
{
	int fd,i,id,ret;
	struct sembuf v;
	char a[20]="1234567890";
	id=semget(10,3,IPC_CREAT|0644);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	fd=open("temp",O_WRONLY|O_CREAT|O_APPEND,0644);

	if(fd<0)
	{
		perror("open");
		return 0;
	}
	v.sem_num=0; //semaphore number
	v.sem_op=0; //semaphore operation(wait for zero)
	//v.sem_flg=0;  //no flags used
	v.sem_flg=IPC_NOWAIT;
	printf("p2 process waiting for lock\n");

	ret=semop(id,&v,1);
	semctl(id,0,SETVAL,1);
	if(ret<0)
	{
		perror("semop");
		return 0;
	}

	printf("p2 process aquire the lock\n");      
	printf("Process2 writing data to file\n");
	for(i=0;a[i];i++)
	{
		write(fd,a+i,1);
		sleep(1);
	}
	printf("p2 process writing data is completed\n");
	sleep(5);
	printf("p2 process going to release resource\n");
	sleep(5);
	semctl(id,0,SETVAL,0);
	printf("p2 process released resource\n");     
}

#include<stdio.h>
#include<sys/sem.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int id,fd,i;
	char a[20]="ABCDEFGHIJKL";
	struct sembuf v;
	id=semget(5,3,IPC_CREAT|0664);
	fd=open("ttt",O_WRONLY|O_CREAT|O_APPEND,0664);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	v.sem_num=1;
	v.sem_op=-1;
	v.sem_flg=0;
	printf("before...\n");
	semop(id,&v,1);
	printf("after...\n");
	printf("P2 process writing data into file...\n");
	for(i=0;a[i];i++)
	{
		write(fd,a+i,1);  //p2 process critical section of code
		sleep(1);
	}
	printf("writing data into file is completed...\n");
	v.sem_num=1;
	v.sem_op=2;
	v.sem_flg=0;
	printf("before...\n");
	semop(id,&v,1);
	printf("after...\n");
}


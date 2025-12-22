#include<stdio.h>
#include<sys/sem.h>
int main()
{
	int id;
	struct sembuf v[2];
	id=semget(5,3,IPC_CREAT|0644);
	if(id<0)
	{
		perror("semget");
		return 0;
	}
	v[0].sem_num=0;
	v[0].sem_op=0;
	v[0].sem_flg=0;

	v[1].sem_num=1;
	v[1].sem_op=0;
	v[1].sem_flg=0;
	printf("Before semop system call");
	semop(id,v,2);
	semctl(id,0,SETVAL,1);
	semctl(id,1,SETVAL,1);
	printf("After semop system call");
}

//write a program to write messages into queue
#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
struct msgbuf
{
	long mtype;
	char mtext[20];
};


int main(int argc,char *argv[])
{
	int id,ret;
	struct msgbuf v;
	id=msgget(5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	//  printf("Message queue is created succesfully with id:%d\n",id);

	if(argc!=3)
	{
		printf("./a.out msg mtype\n");
		return 0;
	}

	v.mtype=atoi(argv[2]);

	//v.mtext=argv[1];

	strcpy(v.mtext,argv[1]);


	ret=msgsnd(id,&v,strlen(v.mtext)+1,0);

	if(ret==-1)
	{
		perror("msgsnd");
		return 0;
	}

	printf("message sent successfully\n");
}


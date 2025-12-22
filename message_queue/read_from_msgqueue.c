//wap to Read messages from Message queue?
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
	int id,ret,msgselection;
	struct msgbuf v;
	id=msgget(5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return 0;
	}

	if(argc!=2)
	{
		printf("./a.out msgseltype\n");
		return 0;
	}

	msgselection=atoi(argv[1]);

	//ret=msgrcv(id,&v,sizeof(v.mtext),msgselection,0);
	ret=msgrcv(id,&v,sizeof(v.mtext),msgselection,IPC_NOWAIT);

	if(ret==-1)
	{
		perror("msgrcv");
		return 0;
	}

	printf("message Reading successfully MSG:%s    MTYPE:%d\n",v.mtext,v.mtype);
}



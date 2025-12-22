#include<stdio.h>
#include<sys/msg.h>
#include<stdlib.h>

struct msgbuf{
	long mtype;
	char mtext[20];
};

int main(int argc,char *argv[])
{
	int id,ret,msgselect;
	struct msgbuf v;
	id = msgget(5,IPC_CREAT|0644);
	if(id<0)
	{
		perror("msgget");
		return 0;
	}
	if(argc != 2)
	{
		printf("./a.out msgtype\n");
		return 0;
	}
	msgselect = atoi(argv[1]);
	ret = msgrcv(id,&v,sizeof(v.mtext),msgselect,IPC_NOWAIT);
	if(ret<0)
	{
		perror("msgrcv");
		return 0;
	}
	printf("msg received : %s \n msg type : %ld \n",v.mtext,v.mtype);
}

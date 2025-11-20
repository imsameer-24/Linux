//full duplex communication using two named pipes?
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int fd1,fd2,ret;
	char a[20],b[20];
	mkfifo("np1",0644);
	mkfifo("np2",0644);

	fd1=open("np1",O_RDONLY);
	fd2=open("np2",O_WRONLY);

	if(fd1<0)
	{
		perror("open");
		return 0;
	}

	if(fd2<0)
	{
		perror("open");
		return 0;
	}
	if(fork()==0)
	{
		while(1)
		{
			ret=read(fd1,b,sizeof(b));
			if(ret<=0)
				exit(0);
			printf("Data Received:%s\n",b);
		}
	}
	else
	{
		while(1)
		{
			scanf("%s",a);
			write(fd2,a,strlen(a)+1);
		}
	}

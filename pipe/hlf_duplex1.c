//half duplex communication using two named pipes?
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd1,fd2;
	char a[20],b[20];
	mkfifo("np1",0644);
	mkfifo("np2",0644);

	fd1=open("np1",O_WRONLY);
	fd2=open("np2",O_RDONLY);

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

	while(1)
	{
		scanf("%s",a);
		write(fd1,a,strlen(a)+1);
		sleep(1);
		read(fd2,b,sizeof(b));
		printf("Data Received:%s\n",b);
	}

}

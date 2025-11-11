#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main()
{
	int fd[2],ret;
	ret=pipe(fd);
	if(ret<0)
	{
		perror("pipe");
		return 0;
	}
	while(1)
	{
	if(fork()==0)
	{
		char a[20];
		printf("Enter the data you want to send : ");
		scanf("%s",a);
		write(fd[1],a,strlen(a)+1);
	}
	else{
		char b[20];
		read(fd[0],b,sizeof(b));
		fcntl(fd[0],F_SETFD,O_NONBLOCK);
		printf("data received : %s\n",b);
	}
	}
}


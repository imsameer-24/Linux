#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd[2],ret;
	ret=pipe(fd);
	if(ret<0)
	{
		perror("pipe");
		return 0;
	}
	if(fork()==0)
	{
		char a[20];
		read(fd[0],a,sizeof(a));
		printf("Received data in child : %s\n");
		sleep(1);
		printf("Enter data in child you want to send :");
		scanf("%s",a);
		write(fd[1],a,strlen(a)+1);

	}
	else
	{

		char a[20];
		printf("Enter data in parent you want to send :");
		scanf("%s",a);
		write(fd[1],a,strlen(a)+1);
		sleep(1);
		read(fd[0],a,sizeof(a));
		printf("Received data in parent : %s\n");
	}
}

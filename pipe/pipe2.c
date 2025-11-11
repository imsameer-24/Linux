#include<stdio.h>
#include<unistd.h>
#include<string.h>
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
		printf("Enter data you want to write : ");
		scanf("%s",a);
		write(fd[1],a,strlen(a)+1);
		sleep(1);
		read(fd[0],a,sizeof(a));
		printf("Received data in chld : %s\n",a);

	}
	else{
		char b[20];
		read(fd[0],b,sizeof(b));
		printf("Received data in prnt : %s\n",b);
		sleep(1);
		printf("Enter data in prnt. you want to write : ");
		scanf("%s",b);
		write(fd[1],b,strlen(b)+1);
	}
}

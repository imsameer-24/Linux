#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int fd[2],ret,count=0;
	char ch='a';
	pipe2(fd,O_NONBLOCK);
	while(ret=write(fd[1],&ch,1)>0)
		count++;
	printf("size of pipe is %d\n",count);
}

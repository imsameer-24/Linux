//half duplex communication using two named pipes?
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd1,fd2,i,j;
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

	while(1)
	{
		read(fd1,b,sizeof(b));
		printf("Data Received:%s\n",b);
		int n=strlen(b);
		char temp;
		for(i=0;i<=n-1;i++){
			for(j=i+1;j<n-i-1;j++){
				if(b[i]>b[j])
				{
					temp=b[i];
					b[i]=b[j];
					b[j]=temp;
				}
			}
		}
		b[i]='\0';
		//scanf("%s",a);
		write(fd2,b,strlen(b)+1);
	}

}

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<fcntl.h>
void *thread1(void *p)
{
	int fd;
	char buf[20];
	fd=open("np1",O_WRONLY);
	if(fd<0)
	{
		perror("open");
		return 0;
	}
	while(1)
	{
		scanf("%s",buf);
		write(fd,buf,strlen(buf)+1);
	}
}

void *thread2(void *p)
{
	int fd;
	char buf[20];
	fd=open("np2",O_RDONLY);
	while(1)
	{
		read(fd,buf,sizeof(buf));
		printf("Data received : %s\n",buf);
	}
}

int main()
{
	pthread_t t1,t2;
	printf("main tharead start\n");
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	mkfifo("np1",0644);
	mkfifo("np2",0644);
	while(1);
}
/*

#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
void* thread1(void *p)
{

   int fd;
   char buf[20];
   fd=open("np1",O_WRONLY);
   if(fd<0)
   {
    perror("open");
    return 0;
   }
 while(1)
 {
   scanf("%s",buf);
   write(fd,buf,strlen(buf)+1);
 }


}
void* thread2(void *p)
{
   int fd;
   char buf[20];
   fd=open("np2",O_RDONLY);
   if(fd<0)
   {
    perror("open");
    return 0;
   }
 while(1)
 {
   read(fd,buf,sizeof(buf));
    printf("Dta Received:%s\n",buf);
 }
}

int main()
{
 pthread_t t1,t2;
 printf("main thread code begins\n");
 pthread_create(&t1,0,thread1,0);
 pthread_create(&t2,0,thread2,0);
 mkfifo("np1",0644);
 mkfifo("np2",0644);

 while(1);
}*/

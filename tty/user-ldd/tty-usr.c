#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/ioctl.h>

int main()
{
	int fd,i,nwrite,nread;
	char *buf ="hello\n";
	char read_buf[6]={0};

	fd=open("/dev/ttty0",O_RDWR);
       //fd = open("/dev/ttyS0",O_RDWR | O_NOCTTY | O_NDELAY);
	if(fd<=0)
	{
		perror("open");
		exit(1);
	}
	else
	{
		printf("open success\n");
	}
	/*
	nwrite = write(fd,buf,strlen(buf));
	if(nwrite<0)
	{
		perror("write");
		exit(1);
	}
        */
	/*nread = read(fd,read_buf,6);
	if(nread<0)
	{
		perror("read");
		exit(1);
	}
	else
 	{
		 printf("read is %s\n",read_buf);
	}
        */ 
	close(fd);

	exit(0);
}


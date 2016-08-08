/*
 ============================================================================
 Name        : helloworld.c
 Author      : shinengqiang
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


/*
	void my_exit(void)
	{ 										ATEXIT TEST
		printf("before exit()!\n");
	}
*/

#include"test.h"

int main()
{
	//printf("PID=%d\r\n",getpid());   PID TEST
	//printf("PPID=%d\r\n",getppid());


	/*if(fork()==0)
	{
	printf("this is the child process\n");  FORK() TEST
	}
	else
	{
	printf("this is the parent process\n");
	}
	*/
/*
	if(fork()==0)
	{
		if(execlp("ps","ps","-ef",NULL)<0)
		{
		perror("execlp  error!") ;
		}
	}
*/
/*
		if(fork()==0)
		{
			if(execl("/bin/ps","ps","-ef",NULL)<0)
			{
				perror("execl  error!") ;
			}
		}

*/
/*
		char *envp[]={"PATH=/tmp","USER=sunq",NULL};

		if(fork()==0)
			{
				if(execle("/usr/bin/env","env",NULL,envp)<0)   ///usr/bin/env  this dir  must be correct .
				{
					perror("execle  error!") ;
				}
			}
*/

/*
	char *arg[]={"env",NULL};
	char *envp[]={"PATH=/tmp","USER=sunq",NULL} ;

		if(fork()==0)
			{
				if(execve("/usr/bin/env",arg,envp)<0)   ///usr/bin/env  this dir  must be correct .
				{
				perror("execve  error!") ;
				}
			}
*/

    // atexit(my_exit) ;  ATEXIT TEST
    //exit(0);

	//execl(“/bin/ls”,”ls”,”-al”,”/etc/passwd”,(char * )0); */


/*
	printf("Using exit ...\n") ;
	printf("this is the content in  buffer") ;
	exit(0);     //exit(0);
*/

	pid_t pc ,pr  ;
	pc=fork();
	if(pc<0)
		printf("Error fork.\n") ;
	else if(pc==0){
		sleep(5);
		exit(0) ;
	}
	else{
		do{
			pr=waitpid(pc,NULL,WNOHANG) ;

			if(pr==0){

				printf("The child process has not exited\n");
				sleep(1);
			}

			}while(pr==0) ;

			if(pr==pc)
				printf("Get child %d",pr) ;
			else
				printf("some error occured .\n") ;
		}


  /*
	pid_t pc ;
	int i ,fd ,len ;
	char *buf="This is a Dameon\n" ;
	len=strlen(buf) ;
	pc=fork();
	if(pc<0){
		printf("error fork \n") ;
		exit(1);
	}else if(pc>0)
	exit(0);

	setsid();
	chdir("/") ;
	umask(0);

	for(i=0;i<MAXFILE;i++)
		close(i) ;
	while(1){
		if(((fd=open("/tmp/dameon.log",O_CREAT|O_WRONLY|O_APPEND,0600)))<0){
			perror("open") ;
			exit(1);

		}
		write(fd,buf,len+1) ;
		close(fd);
		sleep(20) ;

	}
*/
/*
	pid_t pc ,sid ;
	int i ,fd,len;
	char *buf="This is a Dameon\n" ;
	len =strlen(buf) ;
	pc=fork();
	if(pc<0){
		printf("error fork\n") ;
		exit(1) ;
	}else if(pc>0)
	exit(0) ;
	openlog("demo_update",LOG_PID,LOG_DAEMON) ;
	if((sid=setsid())<0){
		syslog(LOG_ERR, "%s\n","setsid");
		exit(1) ;
	}
	if((sid=chdir("/"))<0){
		syslog(LOG_ERR,"%s\n","chdir") ;
		exit(1) ;
	}

	umask(0) ;
	for(i=0;i<MAXFILE;i++)
		close(i) ;

	while(1){

		if(((fd=open("/tmp/dameon.log",O_CREAT|O_WRONLY|O_APPEND,0600)))<0){
					syslog(LOG_ERR,"open") ;
					exit(1);
		}
		write(fd,buf,len+1) ;
		close(fd) ;
		sleep(10) ;

	}
	closelog() ;
	exit(0) ;
   */

	return 0 ;
}


/*com_reader.c*/  
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<sys/types.h>  
#include<sys/stat.h>  
#include<errno.h>  
   
#include<unistd.h>  
#include<termios.h>  
#include<fcntl.h>  
   
#include"open_port_arm9.c"  
#include"set_com_config.c"  
   
#define BUFFER_SIZE 30 /*最大缓存区*/  
#define TARGET_COM_PORT 1      /*用1来表示目标机上的串口1*/  
   
int main(void)  
{  
        int fd;  
        char buff[BUFFER_SIZE];  
   
        if((fd = open_port(TARGET_COM_PORT)) < 0)     /*打开串口*/  
        {  
               perror("open_port");  
               return 1;  
        }  
   
 //       if(set_com_config(fd, 115200, 8, 'N', 1) < 0) /*配置串口*/  
   //     {  
     //          perror("set_com_config");  
       //        return 1;  
       // }  
   
        printf("--1234567\n");
        do  
        {  
//		printf("rgegfg\n");
               memset(buff, 0, BUFFER_SIZE);  
               if(read(fd, buff, BUFFER_SIZE) > 0)  
                       printf("The received words are : %s\n", buff);  
//	printf("fbghmg\n");
        } while(strncmp(buff, "quit", 4));  
        close(fd);  
        return 0;  
}  

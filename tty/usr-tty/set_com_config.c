#include<termios.h>  

int set_com_config(int fd, int baud_rate, \  
               int data_bits, char parity, int stop_bits)  
{  
        struct termios new_cfg,old_cfg;  
        int speed;  
   
        /*步骤一：保存原先串口配置*/  
        if(tcgetattr(fd, &old_cfg) != 0)  
        {  
               perror("tcgetattr");  
               return -1;  
        }  
        new_cfg = old_cfg;  
        /*步骤二：激活选项*/  
        cfmakeraw(&new_cfg);   //config to raw mode  
        /*步骤三：设置字符大小*/  
        new_cfg.c_cflag &= ~CSIZE;     //set mask  
   
        /*步骤四：设置波特率*/  
        switch(baud_rate)  
        {  
               case 2400:  
                       speed = B2400;  
                       break;  
               case 4800:  
                       speed = B4800;  
                       break;  
               case 9600:  
                       speed = B9600;  
                       break;  
               case 19200:  
                       speed = B19200;  
                       break;  
               case 38400:  
                       speed = B38400;  
                       break;  
               default:  
               case 115200:  
                       speed = B115200;  
                       break;  
        }  
        cfsetispeed(&new_cfg, speed);  
        cfsetospeed(&new_cfg, speed);  
   
        /*步骤五：设置数据位*/  
        switch(data_bits)  
        {  
               case 7:  
                       new_cfg.c_cflag |= CS7;  
                       break;  
               default:  
               case 8:  
                       new_cfg.c_cflag |= CS8;  
                       break;  
        }  
   
        /*步骤六：设置奇偶校验位*/  
        switch(parity)  
        {  
               default:  
               case 'n':  
               case 'N':  
                       new_cfg.c_cflag &= ~PARENB;  
                       new_cfg.c_cflag &= ~INPCK;  
                       break;  
          
               case 'o':  
               case 'O':  
                       new_cfg.c_cflag |= (PARODD | PARENB);  
                       new_cfg.c_cflag |= INPCK;  
                       break;  
                         
               case 'e':  
               case 'E':  
                       new_cfg.c_cflag |= PARENB;  
                       new_cfg.c_cflag &= ~PARODD;  
                       new_cfg.c_cflag |= INPCK;  
                       break;  
               case 's':      //as no parity  
               case 'S':  
                       new_cfg.c_cflag &= ~PARENB;  
                       new_cfg.c_cflag &= ~CSTOPB;  
                       break;  
        }//end of 'switch parity'  
   
        /*步骤七：设置停止位*/  
        switch (stop_bits)  
        {  
               default:  
               case 1:  
                       new_cfg.c_cflag &= ~CSTOPB;  
                       break;  
               case 2:  
                       new_cfg.c_cflag |= CSTOPB;  
                       break;  
        }//end of 'switch stop_bits'  
   
        /*步骤八：设置最少字符和等待时间*/  
        new_cfg.c_cc[VTIME] = 0;  
        new_cfg.c_cc[VMIN] = 1;  
   
        /*步骤九：处理未接收的字符*/  
        tcflush(fd,TCIFLUSH);  
   
        /*步骤十：激活新配置*/  
        if((tcsetattr(fd, TCSANOW, &new_cfg)) != 0)  
        {  
               perror("tcsetattr");  
               return -1;  
        }  
        return 0;  
}


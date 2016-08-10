
/*打开开发板串口程序open_port_arm9.c (不同的就只是在char *dev[]那里)*/  
#define MAX_COM_NUM 3  
int open_port(int com_port)  
{  
        int fd;  
//#if (COM_TYPE == GNR_COM)    /*use general Serial port*/  
//      char *dev[] = {"/dev/ttyS0","/dev/ttyS1","/dev/ttyS2"};  
//#else /*use USB turn Serial port*/  
//      char *dev[] = {"/dev/ttyUSB0","/dev/ttyUSB1","/dev/ttyUSB2"};  
        char *dev[] = {"/dev/ttty0","/dev/ttty1","/dev/ttty2"};  
//#endif  
        if((com_port < 0) || (com_port > MAX_COM_NUM))  
               return -1;  
   
        /*打开串口*/  
        fd = open(dev[com_port - 1], O_RDWR | O_NOCTTY | O_NDELAY);  
        if(fd < 0)  
        {  
               perror("open serial port");  
               return -1;  
        }  
   
        /*恢复串口为阻塞状态*/  
        if(fcntl(fd, F_SETFL, 0) < 0)  
        {  
               perror("fcntl F_SETFL\n");  
               return -1;  
        }  
   
        /*测试是否为终端设备*/  
        if(isatty(STDIN_FILENO) == 0)  
        {  
               perror("standard input is not a terminal device");  
               return -1;  
        }  
        return fd;  
}  



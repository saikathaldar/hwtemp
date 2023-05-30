#include<iostream>
#include <sys/socket.h>
#include <netinet/in.h>
//#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>



int main()
{
    sockaddr_in addr_in;
    
  
    int fd;
    ssize_t ret;
    fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd < 0)
    {
        std::cout << "failed socket call";
        return -1;
    }
    addr_in.sin_family=AF_INET;
    addr_in.sin_port=htons(25000);
    inet_pton(AF_INET,"192.168.68.139",&(addr_in.sin_addr));
    if(connect(fd,(sockaddr *)&addr_in,sizeof(addr_in))<0)
    {
        std::cout << "failed connect call";
       return -1;

    }
    char buffer[100];
    strcpy(buffer,"test");
    ret=send(fd,buffer,5,0);

    std::cout << buffer<< ret ;

    close(fd);

    return 0;
}
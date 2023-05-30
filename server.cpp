#include <stdio.h>
//#include<iostream>
#include <sys/socket.h>
#include <netinet/in.h>
//#include <netinet/ip.h>
//#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>




int main()
{
    int fd,fd1,ret;
    struct sockaddr_in addr_in;
    int opt =1;
    int  len = sizeof(addr_in);
    char buffer[1024]={0};

    char* hello = "Hello from server";
    
    
 
    
    fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd < 0)
    {
        //std::cout << "failed socket call";
        exit(0);
    }
    if (setsockopt(fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    addr_in.sin_family=AF_INET;
    addr_in.sin_port=htons(25000);
    addr_in.sin_addr.s_addr = INADDR_ANY;
    //inet_pton(AF_INET,"127.0.0.1",&(addr_in.sin_addr));
    //inet_aton("127.0.0.1",&(addr_in.sin_addr));
    //addr_in.sin_addr.s_addr=inet_addr("127.0.0.1");

    if(bind(fd,(struct sockaddr *)&addr_in,sizeof(addr_in)) < 0)
    {
        //std::cout << "failed bind call";
        exit(0);

    }
    if(listen(fd,3) < 0)
    {
        //std::cout << "failed listen call";
        exit(0);
    }
    fd1=accept(fd,(struct sockaddr *)&addr_in,( socklen_t*)&len);
    if(fd1<0)
    {
        //std::cout << "failed accept call";
        exit(0);
    }
    //std::cout << fd1;
    //while(1)
    //{
    
        ret = read(fd1,buffer,1024);
        if( ret > 0)
        {
        //std::cout << ret;
        buffer[100]=0;
        printf("%s",buffer);
        send(fd1,hello,6,0);
        }

   // }
    close(fd1);
    shutdown(fd,SHUT_RDWR);


    return 0;
}
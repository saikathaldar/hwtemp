#include<iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buffer[100];
    mkfifo("NP.txt",__S_IREAD|__S_IWRITE);
       

    int fd=open("NP.txt",O_RDWR);
    
    
    read(fd,buffer,100);
    std::cout << buffer<<std::endl;
    close(fd);
    
    return 0;
}
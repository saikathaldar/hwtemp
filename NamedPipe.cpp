#include<iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char buffer[100];
    mkfifo("NP.txt",__S_IREAD|__S_IWRITE);

    int fd=open("NP.txt",O_RDWR);


    strcpy(buffer,"test");
    write(fd,buffer,5);
    
    
    close(fd);
    
    return 0;
}
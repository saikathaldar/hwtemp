#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int pipeid[2];
    int pid;
    char * buff[100];

    pipe(pipeid);
    pid = fork();
    if(pid == 0)
    {
        write(pipeid[1],"test34",7);
    }
    else{
        read(pipeid[0],buff,100);
        printf("%s\n",buff);

    }

}

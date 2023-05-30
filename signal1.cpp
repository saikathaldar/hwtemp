#include<iostream>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/types.h>

int main()
{
    int pid=fork();
    if(pid==0)
    {
        for(int i=0;;++i)
            std::cout << "child running" << i << std::endl;
    }
    sleep(2);
    kill(pid,SIGSTOP);
    sleep(2);
    kill(pid,SIGCONT);
    sleep(2);
    kill(pid,SIGKILL);
    for(int i=0;i<64000;++i)
            std::cout << "parent running" << i << std::endl;
    
    return 0;
}
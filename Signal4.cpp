#include<iostream>
#include <signal.h>
#include <unistd.h>

void signalhandler(int sig)
{
    std::cout << "child to parent\n";
}

int main()
{
    int pid = fork();
    if(pid ==0)
    {
        kill(getppid(), SIGUSR1);
    }

    signal(SIGUSR1,signalhandler);


    
    int a;
    std::cin >> a;
    return 0;
}
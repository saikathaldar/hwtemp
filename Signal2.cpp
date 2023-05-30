#include<iostream>
#include <signal.h>


void signalhandler(int sig)
{
    std::cout << "cannot stop\n";
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = &signalhandler;
    sa.sa_flags=SA_RESTART;

    sigaction(SIGTSTP,&sa,NULL);


    
    int a;
    std::cin >> a;
    return 0;
}
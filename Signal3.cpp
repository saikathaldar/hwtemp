#include<iostream>
#include <signal.h>


void signalhandler(int sig)
{
    std::cout << "cannot stop\n";
}

int main()
{
    signal(SIGTSTP,signalhandler);


    
    int a;
    std::cin >> a;
    return 0;
}
#include<iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <fcntl.h>

int main()
{

    void * shared_memory;

    key_t key = ftok("/home/saikath/client.cpp",60);
    std::cout << "key : "<<key<<std::endl;
    int shmid= shmget(key, 1024,__S_IREAD|__S_IWRITE);
    std::cout << "shmid : "<<shmid<<std::endl;
    shared_memory=shmat(shmid,NULL,0);
    printf("%s",(char *)shared_memory);

    return 0;
}
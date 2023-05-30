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
    int shmid= shmget(key, 1024,IPC_CREAT|__S_IREAD|__S_IWRITE);
    std::cout << "shmid : "<<shmid<<std::endl;
    shared_memory = shmat(shmid,NULL,NULL);
    strcpy((char *)shared_memory,"test64");

    return 0;
}
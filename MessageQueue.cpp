#include<iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    struct msgbuf{
        int mtype;
        char mtext[1024];
    };
    key_t key=ftok("/home/saikath/client.cpp",64);
    std::cout << "key : "<<key<<std::endl;
    int msgid= msgget(key,IPC_CREAT|__S_IREAD|__S_IWRITE); 
    std::cout << "msgid : "<<msgid<<std::endl;

    msgbuf msg1;
    msg1.mtype=10;
    strcpy(msg1.mtext,"test10");

    msgsnd(msgid,(void *)&msg1,1024,IPC_NOWAIT);




    return 0;
}
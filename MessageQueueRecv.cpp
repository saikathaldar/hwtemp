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
    std::cout << "key  : "<<key<<std::endl;
    int msgid= msgget(key,IPC_CREAT|__S_IREAD|__S_IWRITE); 
    std::cout << "msgid : "<<msgid<<std::endl;

    msgbuf msg1;
    

    int bytes_recv = msgrcv(msgid,(void *)&msg1,1024,0,IPC_NOWAIT);
    std::cout << "bytes received  = "<<bytes_recv << std::endl;
    
    std::cout << msg1.mtype <<' '<< msg1.mtext;



    return 0;
}
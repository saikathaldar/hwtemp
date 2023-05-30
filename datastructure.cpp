#include <iostream>
#include <map>
#include <array>
#include <queue>


int main()
{

    enum m_type { a1,a2,a3};

    struct s_message{
        char message[100];
        unsigned int mesg_num;
        m_type msg_type;
    };
   
    std::queue<s_message > message_que;

    std::map<std::string,  std::queue<s_message> > host_message_que;
}
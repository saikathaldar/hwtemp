#include <iostream>
#include <map>


int main()
{
    std::map<int,char> relate_i;
    std::map<int,char>::iterator it;

    relate_i.insert({0,'a'});
    relate_i[1]='b';
    
    relate_i[3]='d';


    for(int i=0;i<6;i++)
    {
        std::cout << "i=" << i<<',' << relate_i[i] << std::endl;
    }



}

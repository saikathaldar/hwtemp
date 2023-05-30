#include <iostream>
#include <string.h>
void reverses(char *s_rev, int *i);

int main()
{
    int i=0;
    char str[5]={"abcd"};
    std::cout << str<<std::endl;
    reverses(str,&i);
    std::cout << str;
}

void reverses(char *s_rev, int *i)
{
    if(*i > (strlen(s_rev)/2) -1)
        return;
    char temp;
    temp= s_rev[*i];
    s_rev[*i]= s_rev[strlen(s_rev) -*i -1];
    s_rev[strlen(s_rev) -*i -1]=temp;
    ++*i;
    reverses(s_rev,i);
}
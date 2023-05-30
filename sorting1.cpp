#include <stdio.h>
#include <string.h>



int main( int argc, char * argv[])
{
    char  name[] = "saikatx";
    int name_len = strlen(name);
    for( int i =0; i < name_len ; i++)
    {
        char temp;
        temp = name[i];
        name[i]=name[name_len -1 -i];
        name[name_len -1 -i]= temp;
        if( i >= ((name_len/2)-1))
            break;
    }
    printf("%s",name);

}


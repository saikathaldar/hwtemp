#include <iostream>
#include <string.h>


class Auotmobile{
    
    protected:
    int tyre;
    int body;
    int frame;  
    
    public:
    virtual int build(int , int, int) = 0; 

};

class car: public Auotmobile {
    public:
    car(){};
    int build(int i, int j, int k);
};

class Truck: public Auotmobile {
    public:
    Truck(){};
    int build(int i, int j, int k);
};

int car::build(int i, int j, int k)
{
    tyre = 4;
    body = 5;
    frame = 10;
    return 1;
}

int Truck::build(int i, int j, int k)
{
    tyre = 4;
    body = 5;
    frame = 10;
    return 1;
}


class AutomobileFactory{
    public:

    static Auotmobile * CreateAutomobile(char * AutoType);
    
};

Auotmobile * AutomobileFactory::CreateAutomobile(char * AutoType)
{
    Auotmobile * AutoInst = NULL;

    if(strcmp(AutoType,"car")==0)
    {
        Auotmobile * AutoInst = new car();

    }
    else if(strcmp(AutoType,"Truck")==0)
    {
        Auotmobile * AutoInst = new Truck();
    }
    return AutoInst;
}


int main()
{
    char  AutoType[20];
    //Auotmobile * atuo;
    std::cout << "enter the Auto tyep";
    std::cin >> AutoType;
    
    if(strcmp(AutoType,"car")==0)
        AutomobileFactory::CreateAutomobile("car");
    else if (strcmp(AutoType,"Truck")==0)
    {
        AutomobileFactory::CreateAutomobile("Truck");
    }
}
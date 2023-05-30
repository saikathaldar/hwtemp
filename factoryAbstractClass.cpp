#include <iostream>
#include <string.h>


class Auotmobile{
    
    protected:
    int tyre;
    int body;
    int frame;  
    
    public:
    virtual int build() = 0; 
    virtual void display()=0;

};

class car: public Auotmobile {
    public:
    car(){};
    int build();
    void display();
};

class Truck: public Auotmobile {
    public:
    Truck(){};
    int build();
    void display();
};

int car::build()
{
    tyre = 4;
    body = 5;
    frame = 10;
    return 1;
}
void car::display()
{
    std::cout << tyre <<' '<<body<<' '<<frame<<std::endl;
}
int Truck::build()
{
    tyre = 40;
    body = 50;
    frame = 100;
    return 1;
}
void Truck::display()
{
    std::cout << tyre <<' '<<body<<' '<<frame<<std::endl;
}

class AutomobileFactory{
    public:
    Auotmobile * Auto;

    virtual Auotmobile * CreateAutomobile()=0;
    
};

class CarFactory : public AutomobileFactory {
    public:
    Auotmobile * CreateAutomobile();
};

Auotmobile * CarFactory::CreateAutomobile()
{
    return Auto = new car;
}


class TruckFactory : public AutomobileFactory {
    public:
    Auotmobile * CreateAutomobile();
};

Auotmobile * TruckFactory::CreateAutomobile()
{
        return Auto = new Truck;
}




int main()
{
    char  AutoType[20];
    //Auotmobile * atuo;
    std::cout << "enter the Auto type : ";
    std::cin >> AutoType;
    Auotmobile * autoM;
    AutomobileFactory * MakeAuto;

    if(strcmp(AutoType,"car")==0)
        MakeAuto = new CarFactory;
    else if (strcmp(AutoType,"Truck")==0)
        MakeAuto = new TruckFactory;
    else
        return 1;

    autoM = MakeAuto->CreateAutomobile();
    autoM->build();
    autoM->display();
    return 1;
}
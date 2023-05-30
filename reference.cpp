#include<iostream>
#include <string.h>

struct CarType{
    char VIN[20];
    char Model[20];
    char Make[20];
    char Year[20];
};

class car{
    private:
    int tyre;
    int chasis;
    CarType CType;

    public:
    void PutCarType(CarType & CT);
    void Display();
};
void car::PutCarType(CarType & CT)
{
    strcpy(CType.VIN,CT.VIN);
    strcpy(CType.Model,CT.Model);
    strcpy(CType.Make,CT.Make);
}
void car::Display()
{
    std::cout << CType.Make <<' '<<CType.Model<<' '<<CType.VIN<<std::endl;
}
int main()
{
    CarType CarT;
    strcpy(CarT.VIN,"VIN34fi45owew94");
    strcpy(CarT.Model,"ETIOS");
    strcpy(CarT.Make,"Toyota");

    car TradeCar;
    TradeCar.PutCarType(CarT);
    TradeCar.Display();
    return 0;
}
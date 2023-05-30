#include<iostream>


struct CarType{
    std::string VIN;
    std::string Model;
    std::string Make;

};

class car{
    private:
    int tyre;
    int chasis;
    CarType CType;

    public:
    void PutCarType(CarType & CT, int T, int C);
    void Display();
};
void car::PutCarType(CarType & CT,int T, int C)
{
    CType.VIN=CT.VIN;
    CType.Model=CT.Model;
    CType.Make=CT.Make;
    tyre =T;
    chasis=C;
    
}
void car::Display()
{
    std::cout << CType.Make <<' '<<CType.Model<<' '<<CType.VIN<<' '<<tyre<<' '<<chasis<<std::endl;
}
int main()
{
    CarType CarT;
    CarT.VIN="VIN34fi45owew94";
    CarT.Model="ETIOS";
    CarT.Make="Toyota";

    car TradeCar;
    TradeCar.PutCarType(CarT,10,5000);
    TradeCar.Display();
    return 0;
}
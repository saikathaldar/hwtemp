#include<iostream>
#include <string.h>

template <typename T, typename M, int N>
class EmpName {
private:
T CustId;
M * Name;
int AccNo[N];

public:
void putname(M * x){ strcpy(Name,x);};
M * getname(){ return Name;};

void putCustID(T x){CustId = x;};
T getCustId(){ return CustId;};

void putAccNo(int x, int i){AccNo[i] = x;};
int getAccNo(int i){ return AccNo[i];};

EmpName(){ Name = new M (20);}
~EmpName(){delete Name;}
};

int main()
{
    EmpName<int, char , 2> ename;
    ename.putname((char *)"saikat");
    ename.putCustID(4000);
    ename.putAccNo(40005110,0);
    ename.putAccNo(40005112,1);

    std::cout << ename.getname() <<' '<< ename.getCustId() << ' ';
    std::cout <<  ename.getAccNo(0) <<' '<< ename.getAccNo(1);
    

    return 0;
}
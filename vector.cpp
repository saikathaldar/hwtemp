#include <iostream>
#include <vector>


int main()
{

std::vector<int> cust_id;
std::vector<int>::iterator cust_id_it;

int id = 45;
cust_id.push_back(id);
id=33;
cust_id.push_back(id);

std::cout << cust_id[0]<<std::endl;
std::cout << cust_id[1]<<std::endl;

cust_id_it = cust_id.begin();
std::cout << *cust_id_it <<std::endl;


for(cust_id_it=cust_id.begin(); cust_id_it < cust_id.end(); ++cust_id_it )
{
    std::cout << *cust_id_it <<std::endl;
}





}

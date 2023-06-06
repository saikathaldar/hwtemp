#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <queue>
#include <stack>
#include <list>

/*
using namespace std;
template<typename T>
struct MyAllocator : allocator<T> {
    public:
    T * allocate(int size) {
        cout <<"The size is : "<<size<<endl;
        return new T[size];

    }

};
*/

void* operator new(std::size_t sz) {
    std::printf("global op new called, size = %zu\n",sz);
    return std::malloc(sz);
}
void operator delete(void* ptr) throw()
{
    std::puts("global op delete called");
    std::free(ptr);
}

int main()
{
/*
std::vector<int> v1(4);
std::cout << "The size of vector " << v1.capacity() << std::endl;
v1.push_back(4);
std::cout << "The size of vector " << v1.capacity() << std::endl;
*/
/*
std::deque<int> q1={ 1,8,9,7,9 };
q1.push_back(10);
/*
std::map<int,int> nos;
nos[0]=3434;
nos[1]=3434;


std::map<int,char> ctr;
ctr[0]='a';
ctr[1]='b';

std::map<int,std::string> ctr1;
ctr1[0]="this is testing";
ctr1[1]="sdf";
*/
/*
std::queue<int> q1;
q1.push(10);
q1.push(12);
q1.push(13);
q1.push(13);
q1.push(13);
q1.push(13);
q1.push(13);
*/

/*std::stack<int> s1;
s1.push(10);
s1.push(12);
s1.push(13);
s1.push(13);
s1.push(13);
s1.push(13);
s1.push(13);*/

std::list<int> l1;
l1.push_back(10);
l1.push_back(10);
l1.push_back(10);
l1.push_back(10);
l1.push_back(10);
std::cout<<"end of code\n\n\n";

}

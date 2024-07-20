#include <iostream>
#include "shared_ptr.hpp"


int main()
{
    shared_ptr<int> p1 = new int(9);
    shared_ptr<int> p2 = p1;
    std::cout<<*p1<<std::endl;
    std::cout<<*p2<<std::endl;
    return 0;
}
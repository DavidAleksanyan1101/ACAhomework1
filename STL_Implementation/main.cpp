#include <iostream>
#include "list.hpp"
#include<list>


int main()
{
    mySTL::list<int> l1;
    l1.push_back(5);
    l1.push_back(4);
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(1);
    l1.insert(2 , 45);
    l1.pop_front();
    std::cout<<l1.front()<<std::endl;
    std::cout<<l1.back()<<std::endl;
    l1.print();
    return 0;
}
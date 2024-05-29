#include<iostream>
#include<vector>
#include"vector.hpp"

int main()
{
    std::vector<int> v2;
    myStd::vector<int> v1;
    std::cout << v1.size() << std::endl;
    std::cout << v1.capacity() << std::endl;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }
    
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << " " ;
    }
    std::cout<<std::endl;
    v1.push_front(42);
    v1.push_front(67);
    v1.pop_front();
    v1.insert(47 , 2);
    v1.insert(7 , 4);
    for (int i = 0; i < v1.size(); i++)
    {
        std::cout << v1[i] << " " ;
    }


    return 0;
}
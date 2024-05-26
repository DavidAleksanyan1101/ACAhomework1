#include<iostream>
#include<vector>
#include"vector.hpp"

int main(){
    std::vector<int> v2;
    vector<int> v1;
    std::cout<<v1.size()<<std::endl;
    std::cout<<v1.capacity()<<std::endl;
    v1.push_back(5);
    v1.push_back(5);
    v1.push_back(5);
    v1.pop_back();
    v1.pop_back();
    std::cout<<v1[1]<<std::endl;
    std::cout<<v1.at(1)<<std::endl;
    std::cout<<v1.at(2)<<std::endl;

    return 0;
}
#include "bear.hpp"

void Bear::voice()
{
    std::cout << "I am a bear!" << std::endl;
}

Bear::Bear(const int& age) : Animal("Bear" , age) {}

Bear& Bear::operator=(Bear&& b){
    if(this != &b){
        Animal::operator=(std::move(b));
    }
}

Bear::Bear(Bear&& b): Animal(std::move(b)){}

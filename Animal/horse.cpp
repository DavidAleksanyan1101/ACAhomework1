#include "horse.hpp"

void Horse::voice()
{
    std::cout << "I am a horse!" << std::endl;
}

Horse::Horse(const int& age) : Animal("Horse" , age) {}

Horse& Horse::operator=(Horse&& b){
    if(this != &b){
        Animal::operator=(b);
    }
}

Horse::Horse(Horse&& b): Animal(std::move(b)){}

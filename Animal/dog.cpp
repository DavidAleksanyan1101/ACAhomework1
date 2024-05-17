#include "dog.hpp"

void Dog::voice()
{
    std::cout << "I am a dog!" << std::endl;
}

Dog::Dog(const int& age) : Animal("Dog" , age){}

Dog& Dog::operator=(Dog&& b){
    if(this != &b){
        Animal::operator=(b);
    }
}

Dog::Dog(Dog&& b): Animal(std::move(b)){}

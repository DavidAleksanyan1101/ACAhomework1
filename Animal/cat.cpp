#include "cat.hpp"

void Cat::voice()
{
    std::cout << "I am a cat!" << std::endl;
}

Cat::Cat(const int& age) : Animal("Cat" , age){}

Cat& Cat::operator=(Cat&& c){
    if(this != &c){
        Animal::operator=(c);
    }
}

Cat::Cat(Cat&& b): Animal(std::move(b)){}

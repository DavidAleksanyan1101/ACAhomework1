#include "dog.hpp"

void Dog::voice()
{
    std::cout << "I am a dog!" << std::endl;
}

Dog::Dog(const std::string& name ,const int& age) : Animal(name , age){}
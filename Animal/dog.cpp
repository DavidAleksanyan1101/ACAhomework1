#include "dog.hpp"

void Dog::voice()
{
    std::cout << "I am a dog!" << std::endl;
}

Dog::Dog(const int& age) : Animal("Dog" , age){}
#include "cow.hpp"

void Cow::voice()
{
    std::cout << "I am a cow!" << std::endl;
}

Cow::Cow(const int& age) : Animal("Cow" , age){}

Cow& Cow::operator=(Cow&& c){
    if(this != &c){
        Animal::operator=(c);
    }
}

Cow::Cow(Cow&& b): Animal(std::move(b)){}

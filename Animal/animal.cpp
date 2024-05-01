#include "animal.hpp"

void Animal::getInfo(){
    std::cout<<"Name: "<<_name << "Age: "<<_age<<" Weight: "<<_weight<<std::endl;
}

Animal::Animal(const std::string& name ,const int& age):_name(name), _age(age){}
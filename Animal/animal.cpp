#include "animal.hpp"

void Animal::getInfo(){
    std::cout<<"Name: "<<_name << "Age: "<<_age<<std::endl;
}

Animal::Animal(const std::string& name ,const int& age):_name(name), _age(age){
    count = 0;
    ++count;
}

Animal::Animal(const Animal& a){
    this->_age =a._age;
    this->_name = a._name;
    ++count;
}


Animal::~Animal(){
    --count;
}
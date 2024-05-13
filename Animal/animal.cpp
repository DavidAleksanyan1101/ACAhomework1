#include "animal.hpp"

int Animal::count = 0;

void Animal::getInfo(){
    std::cout<<"Name: "<<_name << "Age: "<<_age<<std::endl;
}

Animal::Animal(const std::string& name ,const int& age):_name(name), _age(age){
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
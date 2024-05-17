#include "animal.hpp"

int Animal::count = 0;

void Animal::getInfo()
{
    std::cout << "Name: " << *_name << "Age: " << *_age << std::endl;
}

Animal::Animal(const std::string& name , const int& age)
{
    _name = new std::string(name);
    _age = new int(age);
    ++count;
}

Animal::Animal(const Animal& a)
{
    this->_age = new int(*a._age);
    this->_name = new std::string(*a._name);
    ++count;
}

Animal& Animal::operator=(const Animal& a){
    if(this != &a){
    delete _name;
    delete _age;

    _name = new std::string(*(a._name));
    _age = new int(*(a._age));
    }
    return *this;
}


Animal::Animal(Animal&& a)
{
    _age = a._age;
    _name = a._name;

    a._age = nullptr;
    a._name = nullptr;

    ++count;
}

Animal& Animal::operator=(Animal&& a)
{
    delete _name;
    delete _age;

    _name = a._name;
    _age = a._age;

    a._age = nullptr;
    a._name = nullptr;
}


Animal::~Animal()
{
    --count;
}
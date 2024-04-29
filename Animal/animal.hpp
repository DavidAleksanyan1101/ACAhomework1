#ifndef __animal__
#define __animal__
#include <iostream>

class Animal
{
public:
    Animal() = default;
    Animal(const std::string& ,const int&);
    virtual ~Animal() = default;
    virtual void voice() = 0;
    void getInfo();
private:
    std::string _name;
    int _age = 0;
};




#endif // __animal__
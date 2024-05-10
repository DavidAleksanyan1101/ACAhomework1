#ifndef __animal__
#define __animal__
#include <iostream>

class Animal
{
public:
    Animal() = default;
    Animal(const std::string& ,const int&);
    Animal(const Animal& a);
    virtual ~Animal();
    virtual void voice() = 0;
    void getInfo();
private:
    std::string _name;
    int _age = 0;
    static int count;
};




#endif // __animal__
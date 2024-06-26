#ifndef __animal__
#define __animal__
#include <iostream>

class Animal
{
public:
    Animal() = default;
    explicit Animal(const std::string& ,const int&);
    Animal(const Animal& a);
    Animal(Animal&& a);
    Animal& operator=(const Animal&);
    Animal& operator=(Animal&&);
    virtual ~Animal();
    virtual void voice() = 0;
    void getInfo();
    bool operator>(const Animal&);
    bool operator<(const Animal&);
    bool operator==(const Animal&);
private:
    std::string* _name = nullptr;
    int* _age = nullptr;
    static int count;
};

#endif // __animal__
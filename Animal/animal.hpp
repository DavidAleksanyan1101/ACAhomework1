#ifndef __animal__
#define __animal__
#include <iostream>

class Animal
{
public:
    virtual void voice() = 0;
};

class Dog : public Animal
{
public:
    void voice() override;
};

class Cat : public Animal
{
public:
    void voice() override;
};

class Bear : public Animal
{
public:
    void voice() override;
};

class Cow : public Animal
{
public:
    void voice() override;
};

class Horse : public Animal
{
public:
    void voice() override;
};



#endif // __animal__
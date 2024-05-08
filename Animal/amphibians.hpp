#ifndef __Amphibians__
#define __Amphibians__
#include "animal.hpp"

class Terrestrial : virtual public Animal
{
public:
    Terrestrial(const std::string& name , const int& age) : Animal(name , age) {}
    virtual void voice() override;
    virtual void run();
    virtual void breathe();
    virtual ~Terrestrial();
};
class Aquatic : virtual public Animal
{
public:
    Aquatic(const std::string& name , const int& age) : Animal(name , age) {}
    virtual void voice() override;
    virtual void swim();
    virtual void breatheUnderWater();
    virtual ~Aquatic();
};

class Amphibians : virtual public Terrestrial , virtual public Aquatic
{
public:
    Amphibians(const std::string& name , const int& age) : Aquatic(name , age) , Terrestrial(name , age) , Animal(name , age) {}
    virtual void voice() override;
    void swim() override;
    void run() override;
    void breathe() override;
    void breatheUnderWater() override;

};


#endif //__Amphibians__
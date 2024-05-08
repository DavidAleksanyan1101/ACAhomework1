#ifndef __Amphibians__
#define __Amphibians__

class Terrestrial
{
public:
    virtual void run();
    virtual void breathe();
    virtual ~Terrestrial();
};
class Aquatic
{
public:
    virtual void swim();
    virtual void breatheUnderWater();
    virtual ~Aquatic();
};

class Amphibians : public Terrestrial , public Aquatic
{
public:
    void swim() override;
    void run() override;
    void breathe() override;
    void breatheUnderWater() override;
    
};


#endif //__Amphibians__
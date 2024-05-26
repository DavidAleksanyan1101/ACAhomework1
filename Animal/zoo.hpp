#ifndef __Zoo__
#define __Zoo__
#include"animal.hpp"


class Zoo
{
public:
    static Zoo& getInstance();
    void showZoo();
    void showBiggestAnimal();
    bool addAnimal(Animal*);
    void removeAnimal(const int&);
private:
    Zoo();
    ~Zoo();
    Zoo(const Zoo&) = delete;
    Zoo& operator=(const Zoo&) = delete;
    static Zoo* instance;
    Animal** _anims;
};


#endif //__Zoo__
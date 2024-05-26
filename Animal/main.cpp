#include "animal.hpp"
#include "bear.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "cow.hpp"
#include "horse.hpp"
#include "zoo.hpp"


int main()
{
    Dog animal1 = 12;
    Cat animal2 = 11;
    Cow animal3  = 5;
    Bear animal4 = 43;
    Horse animal5 = 1;

    Animal* a1 = &animal1;
    Animal* a2 = &animal2;
    Zoo* zoo = &Zoo::getInstance();
    if(*a2 < *a1){
        std::cout<<"aaaaaaaaaaaaaaaa"<<std::endl;
    }

    zoo->addAnimal(&animal1);
    zoo->addAnimal(&animal2);
    zoo->addAnimal(&animal3);
    zoo->addAnimal(&animal4);
    zoo->addAnimal(&animal5);

    zoo->showZoo();
    zoo->showBiggestAnimal();

    return 0;
}
#include "animal.hpp"
#include "bear.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "cow.hpp"
#include "horse.hpp"
#include "zoo.hpp"


int main()
{
    Dog animal1;
    Cat animal2;
    Cow animal3;
    Bear animal4;
    Horse animal5;

    Zoo* zoo = &Zoo::getInstance();

    zoo->addAnimal(&animal1);
    zoo->addAnimal(&animal2);
    zoo->addAnimal(&animal3);
    zoo->addAnimal(&animal4);
    zoo->addAnimal(&animal5);

    zoo->showZoo();

    return 0;
}
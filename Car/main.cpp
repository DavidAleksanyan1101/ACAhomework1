#include"carSubclasses.hpp"
#include "parking.hpp"


int main()
{
    Parking prk(10 , 250);
    Crossover car1("BMW X5 " , "white" , "15 II 550" , 2011 , "Gasoline" , 6 , 3 , 326 , "automatic" , 5);
    car1.offRoadModeEnable();
    car1.comfortModeEnable();
    std::cout << std::endl;

    BMW car2("BMW 330i " , "white" , "01 II 550" , 2017 , "Gasoline" , 4 , 2 , 184 , "automatic" , 5);
    car2.comfortModeEnable();
    car2.driftModeEnabled();
    std::cout << std::endl;

    Cabriolet car3("Ferrari Portofino" , "Red" , "01 II 001" , 2021 , "gasoline" , 8 , 4.2 , 520 , "automatic" , 6);
    car3.sportModeEnable();
    car3.openRoof();
    car3.openRoof();
    std::cout << std::endl;

    Toyota car4("Toyota Camry" , "black" , "32 oo 322" , 2012 , "gasoline" , 4 , 2.5 , 190 , "automatic" , 5);
    car4.ecoModeEnabled();
    car4.ecoModeDisabled();

    return 0;
}
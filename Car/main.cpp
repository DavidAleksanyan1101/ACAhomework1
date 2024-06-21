#include"carSubclasses.hpp"
#include "parking.hpp"
#include<unordered_map>

template<typename T1 , typename T2>
std::pair<T1 , T2> make_pair(T1&& key , T2&& value)
{
    return std::pair<T1 , T2>(key , value);
}


struct CarHash
{
    std::size_t operator()(const Car& c) const
    {
        return std::hash<std::string>{}(c.model) ^ std::hash<int>{}(c.year);
    }
};


int main()
{
    Crossover car1("BMW X5 " , "white" , "15 II 550" , 2011 , "Gasoline" , 6 , 3 , 326 , "automatic" , 5);
    BMW car2("BMW 330i " , "white" , "01 II 550" , 2017 , "Gasoline" , 4 , 2 , 184 , "automatic" , 5);
    Cabriolet car3("Ferrari Portofino" , "Red" , "01 II 001" , 2021 , "gasoline" , 8 , 4.2 , 520 , "automatic" , 6);

    std::unordered_map<Car , std::string , CarHash> unmap;
    unmap.emplace(make_pair(car1 , "davit"));

    std::cout << unmap[car2] << std::endl;
    std::cout << unmap[car1] << std::endl;
    // car1.offRoadModeEnable();
    // car1.comfortModeEnable();
    // std::cout << std::endl;

    // car2.comfortModeEnable();
    // car2.driftModeEnabled();
    // std::cout << std::endl;

    // car3.sportModeEnable();
    // car3.openRoof();
    // car3.openRoof();
    // std::cout << std::endl;

    // Toyota car4("Toyota Camry" , "black" , "32 oo 322" , 2012 , "gasoline" , 4 , 2.5 , 190 , "automatic" , 5);
    // car4.ecoModeEnabled();
    // car4.ecoModeDisabled();


    return 0;
}
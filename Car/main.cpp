#include"car.hpp"
#include "parking.hpp"


int main()
{
    Parking prk(10 , 250);
    Car car1("BMW 330i " , "white" , "30 II 330" , 2017 , "Gasoline" , 4 , 2 , 236 , "automatic" , 5);
    Car car2("Mercedes-Benz " , "black" , "14 II 576" , 2003 , "Gasoline" , 4 , 1.8 , 134 , "manual" , 4);
    Car car3(car1);
    std::cout << prk.carIn(car1) << std::endl;
    std::cout << prk.carIn(car2) << std::endl;
    std::cout << prk.carIn(car3) << std::endl;
    prk.getCarList();
    std::cout << prk.carOut(car2) << std::endl;
    prk.getCarList();


    return 0;
}
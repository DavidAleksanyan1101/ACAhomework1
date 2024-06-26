#include"car.hpp"


Car::Car(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year)
    : model(_model) , color(_color) , numberPlate(_numberPlate) , year(_year)
{
};
Car::Car(const std::string& _model , const std::string& _color , const std::string& _numberPlate , int _year , const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp , const std::string& gearType , const int& gears)
    : model(_model) , color(_color) , numberPlate(_numberPlate) , year(_year)
{
    engine = new Engine(_type , _cylinders , _volume , _hp);
    gearbox = new Gearbox(gearType , gears);
}
Car::Car(const Car& c) : model(c.model) , color(c.color) , numberPlate(c.numberPlate) , year(c.year)
{
    engine = new Engine(*(c.engine));
    gearbox = new Gearbox(*(c.gearbox));
}

Car::~Car()
{
    delete engine;
    delete gearbox;
}

bool Car::operator==(const Car& c) const {
    if(this->model == c.model && this->color == c.color && this->year == c.year){
        return true;
    }
    return false;
}


void Car::printInfo() const
{
    std::cout << "Model: " << model << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Year: " << year << std::endl;
    std::cout << "Number plate: " << numberPlate << std::endl;
}
void Car::printDetailedInfo() const
{
    if (engine == nullptr)
    {
        std::cout << "There is no info about the engine!" << std::endl;
        return;
    }
    std::cout << "Engine info" << std::endl;
    engine->printInfo();
    std::cout << std::endl;
    if (gearbox == nullptr)
    {
        std::cout << "There is no info about the engine!" << std::endl;
        return;
    }
    std::cout << "Gearbox info" << std::endl;
    gearbox->printInfo();
    std::cout << std::endl;
}

void Car::setEngine(const std::string& _type , const int& _cylinders , const int& _volume , const int& _hp)
{
    engine = new Engine(_type , _cylinders , _volume , _hp);
}

void Car::setGearbox(const std::string& gearType , const int& gears)
{
    gearbox = new Gearbox(gearType , gears);
}



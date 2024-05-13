#include "zoo.hpp"

Zoo* Zoo::instance = nullptr;


Zoo::Zoo()
{
    _anims = new Animal * [10];
    for (int i = 0; i < 10; ++i)
    {
        _anims[i] = nullptr;
    }
    std::cout << __func__ << std::endl;
}

Zoo::~Zoo()
{
    delete[] _anims;
    std::cout << __func__ << std::endl;
}

Zoo& Zoo::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Zoo();
    }
    return *instance;
}

void Zoo::showZoo()
{
    for (int i = 0; i < 10; ++i)
    {
        if (_anims[i] != nullptr)
        {
            std::cout << i << ": ";
            _anims[i]->getInfo();
        }
    }

}

bool Zoo::addAnimal(Animal* a)
{
    for (int i = 0; i < 10; i++)
    {
        if (_anims[i] == nullptr)
        {
            _anims[i] = a;
            return true;
        }
    }
    return false;
}
void Zoo::removeAnimal(const int& a)
{
    _anims[a] = nullptr;
}
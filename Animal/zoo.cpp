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

void Zoo::showBiggestAnimal()
{
    Animal* a1 = nullptr;
    Animal* a2 = nullptr;
    Animal* a3 = nullptr;

    for (int i = 1; i < 10; i++)
    {
        if (_anims[i] != nullptr)
        {
            if (a1 == nullptr || *(_anims[i]) > *(a1))
            {
                a3 = a2;
                a2 = a1;
                a1 = _anims[i];
            }
            else if (a2 == nullptr || *(_anims[i]) > *(a2))
            {
                a3 = a2;
                a2 = _anims[i];
            }
            else if (a3 == nullptr || *(_anims[i]) > *(a3))
            {
                a3 = _anims[i];
            }
        }
    }

    std::cout << "1: ";
    a1->getInfo();

    std::cout << "2: ";
    a2->getInfo();

    std::cout << "3: ";
    a3->getInfo();

}
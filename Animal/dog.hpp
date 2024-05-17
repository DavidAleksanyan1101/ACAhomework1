#include "animal.hpp"

class Dog : public Animal
{
public:
    Dog() = default;
    Dog(const int&);
    Dog(Dog&&);
    Dog& operator=(Dog&&);
    void voice() override;
};

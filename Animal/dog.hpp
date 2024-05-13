#include "animal.hpp"

class Dog : public Animal
{
public:
    Dog() = default;
    Dog(const int&);
    void voice() override;
};

#include "animal.hpp"

class Cat : public Animal
{
public:
    Cat() = default;
    Cat(const int&);
    void voice() override;
};

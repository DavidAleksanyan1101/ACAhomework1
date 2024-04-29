#include "animal.hpp"

class Dog : public Animal
{
public:
    Dog() = default;
    Dog(const std::string& ,const int&);
    void voice() override;
};

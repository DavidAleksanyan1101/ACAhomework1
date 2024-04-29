#include "animal.hpp"

class Cat : public Animal
{
public:
    Cat() = default;
    Cat(const std::string& ,const int&);
    void voice() override;
};

#include "animal.hpp"

class Cat : public Animal
{
public:
    Cat() = default;
    Cat(const int&);
    Cat(Cat&&);
    void voice() override;
    Cat& operator=(Cat&&);
    
};

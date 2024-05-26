#include "animal.hpp"

class Horse : public Animal
{
public:
    Horse() = default;
    Horse(const int&);
    Horse(Horse&&);
    Horse& operator=(Horse&&);
    void voice() override;
    
};

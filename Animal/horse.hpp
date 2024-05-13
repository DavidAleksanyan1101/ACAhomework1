#include "animal.hpp"

class Horse : public Animal
{
public:
    Horse() = default;
    Horse(const int&);
    void voice() override;
};

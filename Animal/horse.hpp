#include "animal.hpp"

class Horse : public Animal
{
public:
    Horse() = default;
    Horse(const std::string& ,const int&);
    void voice() override;
};

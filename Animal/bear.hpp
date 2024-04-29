#include "animal.hpp"

class Bear : public Animal
{
public:
    Bear() = default;
    Bear(const std::string& , const int&);
    void voice() override;
};
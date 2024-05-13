#include "animal.hpp"

class Bear : public Animal
{
public:
    Bear() = default;
    Bear( const int&);
    void voice() override;
};
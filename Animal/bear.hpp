#include "animal.hpp"

class Bear : public Animal
{
public:
    Bear() = default;
    Bear( const int&);
    Bear(Bear&& );
    Bear& operator=(Bear&&);
    void voice() override;
};
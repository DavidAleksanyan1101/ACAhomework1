#include "animal.hpp"

class Cow : public Animal
{
public:
    Cow() = default;
    Cow(const int&);
    Cow(Cow&&);
    Cow& operator=(Cow&&);
    void voice() override;
    
};

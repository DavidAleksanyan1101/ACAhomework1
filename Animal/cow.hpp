#include "animal.hpp"

class Cow : public Animal
{
public:
    Cow() = default;
    Cow(const int&);
    void voice() override;
};

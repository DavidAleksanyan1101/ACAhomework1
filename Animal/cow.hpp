#include "animal.hpp"

class Cow : public Animal
{
public:
    Cow() = default;
    Cow(const std::string& ,const int&);
    void voice() override;
};

#ifndef __King__
#define __King__
#include "figure.hpp"

class King : public Figure
{
public:
King(const std::string&);
bool canMove(int , int) override;
private:
};

#endif // __King__
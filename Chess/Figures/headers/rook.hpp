#ifndef __Rook__
#define __Rook__
#include "figure.hpp"

class Rook : public Figure
{
public:
Rook(const std::string&);
bool canMove(int , int) override;
private:
};


#endif //__Rook__
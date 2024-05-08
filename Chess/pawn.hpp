#ifndef __Pawn__
#define __Pawn__
#include "figure.hpp"

class Pawn : public Figure
{
public:
Pawn(const std::string&);
bool canMove(int , int) override;
private:

};


#endif //__Pawn__
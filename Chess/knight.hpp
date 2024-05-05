#ifndef __Knight__
#define __Knight__
#include "figure.hpp"

class Knight : public Figure
{
public:
Knight(const std::string&);
bool canMove(int , int) override;
private:

};

#endif //__Knight_
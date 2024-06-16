#ifndef __Bishop__
#define __Bishop__
#include "figure.hpp"


class Bishop : public Figure
{
public:
Bishop(const std::string&);
bool canMove(int , int) override;
private:

};


#endif //__Bishop__
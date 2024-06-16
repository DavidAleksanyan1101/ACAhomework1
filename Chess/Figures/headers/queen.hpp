#ifndef __Queen__
#define __Queen__
#include "figure.hpp"

class Queen : public Figure
{
public:
Queen(const std::string&);
bool canMove(int , int) override;
private:
};


#endif //__Queen__
#ifndef __Figure__
#define __Figure__
#include<iostream>

class Figure
{
public:
    Figure(const std::string& ,const std::string&);
    virtual ~Figure();
public:
    virtual void move(int , int) = 0;
    virtual bool canMove(int , int) = 0;
    std::string getName();
    std::string getColor();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
private:
    std::string _color;
    std::string _name;
    int x = 0;
    int y = 0;
};

#endif //__Figure__
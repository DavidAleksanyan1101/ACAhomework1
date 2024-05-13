#include <iostream>

class INT{
public:
    INT(int x = 0): a(x){}

    INT& operator++(){
        ++a;
        return *this;
    }
    
    INT operator++(int){
        INT temp = *this;
        ++a;
        return temp;
    }

    friend std::ostream& operator << (std::ostream& os, const INT& a);
private:
    int a = 0;
};

std::ostream& operator << (std::ostream& os, const INT& a)
{
    os << a.a;
    return os;
}

int main() {
    INT x = 5;
    
    std::cout<<++x<<std::endl;
    std::cout<<x++<<std::endl;
    std::cout<<x<<std::endl;

    return 0;
}
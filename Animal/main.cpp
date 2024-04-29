#include "animal.hpp"


int main() {
    Dog animal1;
    Cat animal2;
    Cow animal3;
    Bear animal4;
    Horse animal5;

    Animal** ptr = new Animal*[5];
    ptr[0] = &animal1;
    ptr[1] = &animal2;
    ptr[2] = &animal3;
    ptr[3] = &animal4;
    ptr[4] = &animal5;

    for (int i = 0; i < 5; ++i)
    {
        ptr[i]->voice();
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

bool isPrime(const int& a)
{
    if (a <= 1)
    {
        return false;
    }
    for (int i = 2; i < sqrt(a); ++i)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    std::vector<int> v1{ 12 , 32, 29 , 14 , 3 , 7 , 81 , 45 , 87 , 11 , 90  , 37 };

    v1.erase(remove_if(v1.begin() , v1.end() , [](int a) -> bool { return isPrime(a); }) , v1.end());



    for (auto it : v1)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;


    return 0;
}
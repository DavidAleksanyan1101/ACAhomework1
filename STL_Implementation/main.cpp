#include <bits/stdc++.h>
#include "forward_list.hpp"
#include "iterators/input_iterator.hpp"
#include "stackList.hpp"

template <typename T>
void printMyList(const mySTL::forward_list<T> &list)
{
    for (input_iterator<int> it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

bool isPrime(const int &a)
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

template <typename T>
void printVec(std::vector<T> vec)
{
    for (auto &it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printList(std::list<T> list)
{
    for (auto &it : list)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

void deletePrimes(std::vector<int> &vec)
{
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        if (isPrime(*it))
        {
            it = vec.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void deleteSmallerMedian(std::list<int> &list)
{
    std::list<int>::iterator it = list.begin();
    int median = 0;
    for (auto i : list)
    {
        median += i;
    }
    median /= list.size();
    while (it != list.end())
    {
        if (*it < median)
        {
            it = list.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

std::string intToString(const int &a)
{
    static std::map<int , std::string> mp;
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";

    return mp[a];

}

int main()
{
    std::cout<<intToString(5)<<std::endl;
    std::cout<<intToString(6)<<std::endl;

    return 0;
}
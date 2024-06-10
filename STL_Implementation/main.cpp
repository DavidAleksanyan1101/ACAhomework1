#include <iostream>
#include "forward_list.hpp"
#include "iterators/input_iterator.hpp"
#include <vector>
#include <list>
#include <cmath>

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

int main()
{
    std::vector v1{23, 45, 3, 76, 88, 91, 11, 14, 7};
    printVec(v1);
    deletePrimes(v1);
    printVec(v1);
    std::cout<<std::endl;

    std::list<int> l1{32, 123, 43, 12, 65, 89, 230, 150};
    printList(l1);
    deleteSmallerMedian(l1);
    printList(l1);

    return 0;
}
#include <iostream>
#include "forward_list.hpp"
#include "iterators/input_iterator.hpp"

template <typename T>
void printList(const mySTL::forward_list<T>& list)
{
    for (input_iterator<int> it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
    mySTL::forward_list<int> fl;
    fl.push_front(5);
    fl.push_front(34);
    fl.push_front(9);
    fl.push_front(98);

    printList(fl);
    
    return 0;
}
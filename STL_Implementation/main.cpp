#include <iostream>
#include "mySTL.hpp"
#include<forward_list>

template<typename T>
bool cycleCheck(mySTL::forward_list<T> list)
{
    Node<T>* first = list.head;
    Node<T>* second = list.head;
    while (first->next != nullptr || second->next != nullptr)
    {
        first = first->next;
        second = second->next->next;
        if(first == second ){
            return true;
        }
    }
    return false;
}

int main()
{
    mySTL::Node<std::string> n("ddd5");
    mySTL::forward_list<int> sl;
    std::string s1 = "6";
    sl.push_front(1);
    sl.push_front(2);
    sl.push_front(3);
    sl.push_front(4);
    sl.push_front(5);
    sl.print();
    sl.insert(0 , 45);
    sl.print();
    sl.pop_front();
    sl.print();
    return 0;
}
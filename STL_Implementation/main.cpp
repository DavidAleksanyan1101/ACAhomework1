#include <iostream>
// #include "mySTL.hpp"
#include "forward_list.hpp"


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
    sl.insert(0 , 6);
    sl.print();
    sl.reverse();
    sl.print();

    sl.cycleCheck();

    return 0;
}
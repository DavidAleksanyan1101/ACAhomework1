#ifndef __stackList__
#define __stackList__
#include "forward_list.hpp"

namespace mySTL
{
    template <typename T>
    class stack : private forward_list<T>
    {
    public:
        stack() = default;
        stack(const stack &other) : forward_list<T>(other){};
        T &top();
        void push(const T &);
        void pop();
    };

    template <typename T>
    T &stack<T>::top()
    {
        return forward_list<T>::front();
    }

    template <typename T>
    void stack<T>::push(const T &t)
    {
        forward_list<T>::push_front(t);
    }

    template <typename T>
    void stack<T>::pop()
    {
        forward_list<T>::pop_front();
    }

};
#endif //__stackList__
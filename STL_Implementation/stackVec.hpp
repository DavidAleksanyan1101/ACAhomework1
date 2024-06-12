#ifndef __stackVec__
#define __stackVec__
#include "vector.hpp"
namespace mySTL
{
    template <typename T>
    class stack : private vector<T>
    {
    public:
        stack() = default;
        stack(const stack &other) : vector<T>(other){};
        T &top();
        void push(const T &);
        void pop();
    };

    template <typename T>
    T &stack<T>::top()
    {
        return vector<T>::back();
    }

    template <typename T>
    void stack<T>::push(const T &t)
    {
        vector<T>::push_back(t);
    }

    template <typename T>
    void stack<T>::pop()
    {
        vector<T>::pop_back();
    }

};
#endif //__stackVec__
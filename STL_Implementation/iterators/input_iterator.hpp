#ifndef __input_iterator__
#define __input_iterator__
#include "../forward_list.hpp"

template <typename T>
class input_iterator
{
public:
    input_iterator() = default;
    input_iterator(mySTL::Node<T>*);
    input_iterator(const input_iterator &);
public:
    input_iterator& operator++();
    input_iterator operator++(int);
    void operator=(const input_iterator&);
    bool operator!=(const input_iterator&);
    bool operator==(const input_iterator&);
    T &operator*();

private:
    mySTL::Node<T> *ptr = nullptr;
};

template <typename T>
input_iterator<T>::input_iterator(mySTL::Node<T> *n) : ptr(n) {}
template<typename T>
input_iterator<T>::input_iterator(const input_iterator<T>& it) : ptr(it.ptr){}

template <typename T>
input_iterator<T>& input_iterator<T>::operator++()
{
    ptr = ptr->next;
}

template <typename T>
input_iterator<T> input_iterator<T>::operator++(int)
{
    input_iterator<T> temp = *this;
    ptr = ptr->next;
    return temp;
}

template <typename T>
T &input_iterator<T>::operator*()
{
    return ptr->data;
}

template <typename T>
void input_iterator<T>::operator=(const input_iterator<T>& it)
{
    ptr = it.ptr;
}

template<typename T>
bool input_iterator<T>::operator!=(const input_iterator<T>& it){
    if(ptr != it.ptr){
        return true;
    }
    return false;
}

template<typename T>
bool input_iterator<T>::operator==(const input_iterator<T>& it){
    if(ptr == it.ptr){
        return true;
    }
    return false;
}

#endif //__input_iterator__
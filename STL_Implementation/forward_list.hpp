#ifndef __forward_list__
#define __forward_list__

template <typename T>
class Node
{
public:
    Node(const T &);

public:
    Node *next = nullptr;
    T data;
};

template <typename T>
class forward_list
{
public:
    forward_list() = default;
    forward_list(const Node<T> &);
    forward_list(const T &);

public:
    void push_front(const Node);

private:
    Node<T> *head = nullptr;
};

template <typename T>
Node<T>::Node(const T &_data)
{
    data = _data;
}

template <typename T>
forward_list<T>::forward_list(const Node<T> &n)
{
    head = new Node(n.data);
}

template <typename T>
forward_list<T>::forward_list(const T& n)
{
    head = new Node(n.data);
}

#endif //__forward_list__

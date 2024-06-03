#ifndef __forward_list__
#define __forward_list__

template <typename T>
class Node
{
public:
    Node(const T&);

public:
    Node* next = nullptr;
    T data;
};

template <typename T>
class forward_list
{
public:
    forward_list() = default;
public:
    void push_front(const Node<T>&);
    void push_front(const T&);
    void pop_front();
    void insert(const int& index , const T&);
    void print();
private:
    Node<T>* head = nullptr;
};

template <typename T>
Node<T>::Node(const T& _data)
{
    data = _data;
}

// template <typename T>
// forward_list<T>::forward_list(const Node<T>& n)
// {
//     head = new Node<T>(n.data);
// }

// template <typename T>
// forward_list<T>::forward_list(const T& n)
// {
//     head = new Node<T>(n);
// }

template<typename T>
void forward_list<T>::push_front(const Node<T>& n)
{
    if (head != nullptr)
    {
        Node<T>* tmp = new Node<T>(n.data);
        tmp->next = head;
        head = tmp;
        return;
    }
    head = new Node<T>(n.data);
}

template<typename T>
void forward_list<T>::push_front(const T& n)
{
    if (head != nullptr)
    {
        Node<T>* tmp = new Node<T>(n);
        tmp->next = head;
        head = tmp;
        return;
    }
    head = new Node<T>(n);
}

template<typename T>
void forward_list<T>::pop_front()
{
    Node<T>* tmp = head;
    head = tmp->next;
    delete tmp;
}
template<typename T>
void forward_list<T>::insert(const int& index , const T& t)
{
    if (index != 0)
    {
        Node<T>* tmp = head;
        for (int i = 0; i < index - 1; i++)
        {
            tmp = tmp->next;
        }
        Node<T>* newNode = new Node<T>(t);
        newNode->next = tmp->next;
        tmp->next = newNode;
        return;
    }
    this->push_front(t);
}

template<typename T>
void forward_list<T>::print()
{
    if(head != nullptr){
    std::cout<< head->data<<" ";
    for (Node<T>* i = head; i->next != nullptr; i = i->next)
    {
        std::cout<< i->next->data<<" ";
    }
    std::cout<<std::endl;
    }
}

#endif //__forward_list__

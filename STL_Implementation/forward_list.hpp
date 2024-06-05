#include <stack>
#ifndef __forward_list__
#define __forward_list__

namespace mySTL
{
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

    public:
        void push_front(const Node<T> &);
        void push_front(const T &);
        void pop_front();
        void insert(const int &index, const T &);
        void makeCycle();
        bool cycleCheck();
        T lastNthElem(const int &);
        void print();
        void reverse();
        int size();

    private:
        Node<T> *head = nullptr;
    };

    template <typename T>
    Node<T>::Node(const T &_data)
    {
        data = _data;
    }

    template <typename T>
    void forward_list<T>::push_front(const Node<T> &n)
    {
        if (head != nullptr)
        {
            Node<T> *tmp = new Node<T>(n.data);
            tmp->next = head;
            head = tmp;
            return;
        }
        head = new Node<T>(n.data);
    }

    template <typename T>
    void forward_list<T>::push_front(const T &n)
    {
        if (head != nullptr)
        {
            Node<T> *tmp = new Node<T>(n);
            tmp->next = head;
            head = tmp;
            return;
        }
        head = new Node<T>(n);
    }

    template <typename T>
    void forward_list<T>::pop_front()
    {
        Node<T> *tmp = head;
        head = tmp->next;
        delete tmp;
    }
    template <typename T>
    void forward_list<T>::insert(const int &index, const T &t)
    {
        if (index != 0)
        {
            Node<T> *tmp = head;
            for (int i = 0; i < index - 1; i++)
            {
                tmp = tmp->next;
            }
            Node<T> *newNode = new Node<T>(t);
            newNode->next = tmp->next;
            tmp->next = newNode;
            return;
        }
        this->push_front(t);
    }

    template <typename T>
    bool forward_list<T>::cycleCheck()
    {
        Node<T> *first = head->next;
        Node<T> *second = head->next->next;
        while (first != nullptr || second != nullptr)
        {
            if (first == second)
            {
                return true;
            }
            first = first->next;
            second = second->next->next;
        }
        return false;
    }

    template <typename T>
    int forward_list<T>::size()
    {
        int count = 0;
        if (head != nullptr)
        {
            Node<T> *tmp = head;
            while (tmp != nullptr)
            {
                ++count;
                tmp = tmp->next;
            }
        }
        return count;
    }

    template <typename T>
    void forward_list<T>::print()
    {
        if (head != nullptr)
        {
            std::cout << head->data << " ";
            for (Node<T> *i = head; i->next != nullptr; i = i->next)
            {
                std::cout << i->next->data << " ";
            }
            std::cout << std::endl;
        }
    }

    template <typename T>
    void forward_list<T>::reverse()
    {
        if (head != nullptr)
        {
            std::stack<T> st;
            Node<T> *tmp = head;
            while (true)
            {
                st.push(tmp->data);
                if (tmp->next != nullptr)
                {
                    tmp = tmp->next;
                    continue;
                }
                break;
            }
            tmp = head;
            while (true)
            {
                tmp->data = st.top();
                st.pop();
                if (tmp->next != nullptr)
                {
                    tmp = tmp->next;
                    continue;
                }
                break;
            }
        }
    }

template <typename T>
T forward_list<T>::lastNthElem(const int &a)
{
    if (a >= this->size())
    {
        throw std::out_of_range(" ");
    }
    
    Node<T>* tmp = head;
    for (int i = 0; i < this->size() - a - 1; i++)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}


};


#endif //__forward_list__

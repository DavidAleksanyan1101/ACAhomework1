#ifndef __list__
#define __list__

namespace mySTL
{

    template<typename T>
    class list
    {
        class Node
        {
        public:
            Node(const T&);
        public:
            Node* prev = nullptr;
            Node* next = nullptr;
            T data;
        };
    public:
        T& front();
        T& back();
        bool empty();
        int size();
        void push_front(const T&);
        void push_back(const T&);
        void pop_front();
        void pop_back();
        void insert(const int& , const T&);
        void print();
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
    };

    template <typename T>
    list<T>::Node::Node(const T& _data) :data(_data) {}

    template<typename T>
    T& list<T>::front()
    {
        return head->data;
    }

    template<typename T>
    T& list<T>::back()
    {
        return tail->data;
    }

    template<typename T>
    bool list<T>::empty()
    {
        if (head != nullptr)
        {
            return false;
        }
        return true;
    }

    template<typename T>
    int list<T>::size()
    {
        int count = 0;
        if (head != nullptr)
        {
            Node* tmp = head;
            while (tmp != nullptr)
            {
                ++count;
                tmp = tmp->next;
            }
        }
        return count;
    }

    template<typename T>
    void list<T>::push_front(const T& t)
    {
        if (head != nullptr)
        {
            Node* tmp = new Node(t);
            head->prev = tmp;
            tmp->next = head;
            head = tmp;
            return;
        }
        head = new Node(t);
        tail = head;
    }

    template<typename T>
    void list<T>::push_back(const T& t)
    {
        if (head == nullptr)
        {
            head = new Node(t);
            tail = head;
            return;
        }
        Node* tmp = new Node(t);
        tmp->prev = tail;
        tail->next = tmp;
        tail = tmp;
        return;
    }

    template<typename T>
    void list<T>::pop_front()
    {
        if (head != nullptr)
        {
            Node* tmp = head;
            head = head->next;
            head->prev = nullptr;
            delete tmp;
            if (head == nullptr)
            {
                tail = nullptr;
            }
        }
    }

    template<typename T>
    void list<T>::pop_back()
    {
        if (tail != nullptr)
        {
            Node* tmp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete tmp;
            if (tail == nullptr)
            {
                head = nullptr;
            }
        }
    }

    template<typename T>
    void list<T>::insert(const int& index , const T& t)
    {
        if(index >= this->size()){
            throw std::out_of_range("invalid index");
        }
        if (index != 0)
        {
            Node* tmp = head;
            for (int i = 0; i < index; i++)
            {
                tmp = tmp->next;
            }
            Node* newNode = new Node(t);
            newNode->next = tmp;
            newNode->prev = tmp->prev;
            tmp->prev = newNode;
            newNode->prev->next = newNode;
            return;
        }
        this->push_front(t);
    }

    template<typename T>
    void list<T>::print()
    {
        if (head != nullptr)
        {
            Node* tmp = head;
            while (tmp != nullptr)
            {
                std::cout << tmp->data << " ";
                tmp = tmp->next;
            }
        }
    }
};
#endif //__list__
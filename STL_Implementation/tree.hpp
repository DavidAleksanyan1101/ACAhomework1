#ifndef __tree__
#define __tree__
#include <iostream>

template <typename T>
class BinaryTree
{
public:
    struct Node
    {
        T data;
        Node* left;
        Node* right;
        Node(T value) : data(value) , left(nullptr) , right(nullptr) {}
    };
    
public:
    BinaryTree() = default;
    void insert(const T& value);   
private:
    void insertLogic(Node* , const T&);
private:
    Node* root == nullptr;

};

template<typename T>
void insertLogic(Node* node , const T& value)
{
    if (value < node->data)
    {
        if (node->left == nullptr)
        {
            node->left = new Node(value);
        }
        else
        {
            insertLogic(node->left , value);
        }
    }
    else
    {
        if (node->right == nullptr)
        {
            node->right = new Node(value);
        }
        else
        {
            insertLogic(node->right , value);
        }
    }
}

template<typename T>
void insert(const T& value)
{
    if (root == nullptr)
    {
        root = new Node(value);
    }
    else
    {
        insertLogic(root , value);
    }
}

#endif //__tree__

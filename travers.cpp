#include <bits/stdc++.h>

template<typename T>
struct Node
{
    // Node() = default;
    Node(const T& _data) : data(_data) {}
    T data;
    Node* right = nullptr;
    Node* left = nullptr;
};



template<typename T>
void insertNode(Node<T>* root , const T& t)
{
    if (root == nullptr)
    {
        root = new Node<T>(t);
        return;
    }

    std::queue<Node<T>*> que;
    que.push(root);
    while (!que.empty())
    {
        Node<T>* temp = que.front();
        que.pop();

        if (temp->left != nullptr)
        {
            que.push(temp->left);
        }
        else
        {
            temp->left = new Node<T>(t);
            return;
        }

        if (temp->right != nullptr)
        {
            que.push(temp->right);
        }
        else
        {
            temp->right = new Node<T>(t);
            return;
        }
    }
}


template<typename T>
void inorderTravers(Node<T>* tree)
{
    if (tree == nullptr)
    {
        return;
    }

    inorderTravers(tree->left);
    std::cout << tree->data<<" ";
    inorderTravers(tree->right);
}

template<typename T>
void preorderTravers(Node<T>* tree)
{
    if (tree == nullptr)
    {
        return;
    }

    std::cout << tree->data<<" ";
    preorderTravers(tree->left);
    preorderTravers(tree->right);
}

template<typename T>
void postorderTravers(Node<T>* tree)
{
    if (tree == nullptr)
    {
        return;
    }

    postorderTravers(tree->left);
    postorderTravers(tree->right);
    std::cout << tree->data<<" ";
}

template<typename T>
void levelOrderTravers(Node<T>* root)
{
    if (root == nullptr)
        return;


    std::queue<Node<T>*> que;
    que.push(root);

    while (!que.empty()) {
        Node<T>* node = que.front();
        que.pop();
        std::cout << node->data << " ";

        if (node->left != nullptr)
            que.push(node->left);
        if (node->right != nullptr)
            que.push(node->right);
    }
}



int main()
{
    Node<int>* tree = new Node<int>(1);
    insertNode(tree , 2);
    insertNode(tree , 3);
    insertNode(tree , 4);
    insertNode(tree , 5);

    std::cout<<"Inorder  ";
    inorderTravers(tree);
    std::cout<<std::endl;
    std::cout<<"prerder  ";
    preorderTravers(tree);
    std::cout<<std::endl;
    std::cout<<"postrder  ";
    postorderTravers(tree);
    std::cout<<std::endl;
    std::cout<<"level order  ";
    levelOrderTravers(tree);


}


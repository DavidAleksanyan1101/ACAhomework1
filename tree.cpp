#include<bits/stdc++.h>


template <typename T>
struct Node
{
    std::vector<Node*> node_vec;
    T val;
    void push(Node<T>* node)
    {
        node_vec.push_back(node);
    }
    Node(T val) : val(val)
    {
    }
};
template <typename T>
struct Tree
{
    Node<T>* root;
public:
    void travers()
    {
        std::queue<Node<T>*> q;
        q.push(root);
        while (!q.empty())
        {
            auto* temp = q.front();
            std::cout << temp->val << std::endl;
            q.pop();
            for (auto* in : temp->node_vec)
            {
                q.push(in);
            }
        }
    }
    Tree(Node<T>* node) : root(node)
    {
    }
};

Tree<int>& randomTree()
{
    std::srand(time(0));
    int layers = rand()%10 + 1;
    // std::cout << layers;
    Tree<int>* t1 = new Tree<int>(new Node<int>(rand()%10 + 1));
    std::queue<Node<int>*> que;
    que.push(t1->root);
    for (int i = 1; i < layers; i++)
    {
        Node<int>* temp = que.front();
        que.pop();
        for (int i = 0; i < rand()%10 + 1; i++)
        {
            temp->push(new Node<int>(rand()%10 + 1));
            que.push(temp->node_vec.back());
        }
    }
    return *t1;
}


int main()
{
    Tree<int>* tree = &randomTree();
    tree->travers();
    return 0;
}
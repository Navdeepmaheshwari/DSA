#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    // Constructor
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
bool isSameTree(Node *p, Node *q)
{

    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;

    if (p->key != q->key)
        return false;
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main()
{
    Node *root1 = new Node(20);
    root1->left = new Node(8);
    root1->right = new Node(12);

    Node *root2 = new Node(20);
    root2->left = new Node(8);
    root2->right = new Node(12);
    bool ans = isSameTree(root1, root2);
    if (ans)
    {
        cout << "Same Tree";
    }
    else{
        cout << "Not Same Tree";
    }
}
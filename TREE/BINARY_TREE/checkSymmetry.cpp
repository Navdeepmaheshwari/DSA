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

bool checkSymmetry(Node *x, Node *y)
{
    if (x == NULL && y == NULL)
        return true;
    if (x == NULL || y == NULL)
        return false;

    if (x->key != y->key)
        return false;

    return (checkSymmetry(x->left, y->right) &&
            checkSymmetry(x->right, y->left));
}
bool isSymmetric(Node *root)
{

    return checkSymmetry(root->left, root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    // root->left->right->left = new Node(70);
    // root->left->right->right = new Node(80);
    root->right = new Node(2);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    bool ans = isSymmetric(root);
    if (ans)
    {
        cout << "Symmetric Tree";
    }
    else
    {
        cout << "Not Symmetric Tree";
    }
}
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

int mxm(Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    else
    {
        return (max(root->key, max(mxm(root->left), mxm(root->right))));
    }
}
int main()
{
    // Node *root = NULL;
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right = new Node(30);
    root->right->right = new Node(60);
    int treemxm = mxm(root);
    cout << treemxm << endl;
}
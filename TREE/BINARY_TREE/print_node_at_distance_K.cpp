/*
In this question we have to print Nodes at distance k from Root Node.
Simpliy we have to print all Node at Level K+1.
for K=0, we have to print root.
*/

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

void printNodeatK(Node *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->key << " ";
    }
    else
    {
        printNodeatK(root->left, k - 1);
        printNodeatK(root->right, k - 1);
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right = new Node(30);
    root->right->right = new Node(60);

    printNodeatK(root, 3);
}
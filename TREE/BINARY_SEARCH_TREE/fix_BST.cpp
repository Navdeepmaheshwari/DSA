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

Node *pre = NULL, *first = NULL, *second = NULL;
// maintain 3 pointers
void fixBST(Node *root)
{
    if (root == NULL)
        return;
    fixBST(root->left);
    if (pre != NULL && root->key < pre->key)
    {

        if (first == NULL)
        {
            first = pre;
        }
        second = root;
    }
    pre = root;
    fixBST(root->right);

    // swap(first->key, second->key);
}

void inOrder(Node *root)
{

    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    };
}
int main()
{
    Node *root = new Node(18);
    root->left = new Node(60);
    root->left->left = new Node(40);
    // root->left->right = new Node(40);

    root->right = new Node(70);
    root->right->left = new Node(8);
    root->right->right = new Node(80);

    cout << "Before Fixing : ";
    inOrder(root);

    cout << "\nAfter Fixing : ";
    fixBST(root);
    swap(first->key, second->key);
    inOrder(root);
}
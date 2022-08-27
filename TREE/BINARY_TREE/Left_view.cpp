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

int maxlevel = 0;

void printLeft(Node *root, int level)
{
    if (root == NULL)
        return;

    if (maxlevel < level)
    {
        cout << root->key << " ";
        maxlevel = level;
    }

    printLeft(root->left, level + 1);
    printLeft(root->right, level + 1);
}

void printLeftView(Node *root)
{
    printLeft(root, 1);
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
    printLeftView(root);
}
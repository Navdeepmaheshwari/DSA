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

/*
    RECURSIVE SOLUTION
    TIME COMPLEXITY: O(h)
    SPACE COMPLEXITY: O(h)
*/

bool searchBST(Node *root, int x)
{

    if (root == NULL)
        return false;
    if (root->key == x)
        return true;
    else if (root->key > x)
        return searchBST(root->left, x);
    else
        return searchBST(root->right, x);
}
int main()
{
    Node *root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(10);
    root->left->right = new Node(40);

    root->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    bool issearch = searchBST(root, 10);
    if (issearch)
    {
        cout << "present";
    }
}
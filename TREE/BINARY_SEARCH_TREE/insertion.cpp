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
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

/*
    RECURSIVE SOLUTION
    TIME COMPLEXITY: O(h)
    SPACE COMPLEXITY: O(h)
*/

Node *insertBST(Node *root, int x)
{

    if (root == NULL)
        return new Node(x);
    else if (root->key < x)
        root->right = insertBST(root->right, x);
    else if (root->key > x)
        root->left = insertBST(root->left, x);

    return root;
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

    inOrder(root);
    cout << endl;
    Node *newroot = insertBST(root, 0);
    inOrder(newroot);
}
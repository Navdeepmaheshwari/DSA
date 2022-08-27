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

int minDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = minDepth(root->left);
    int rightHeight = minDepth(root->right);
    if (leftHeight == 0)
        return 1 + rightHeight; 
        // leftHeight=0 means there is no left subtree,so we cannot compare its height to right subtree
    else if (rightHeight == 0)
        return 1 + leftHeight; 
        // rightHeight=0 means there is no right subtree
    else
        return 1 + min(leftHeight, rightHeight);
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
    int treeminDepth = minDepth(root);
    cout << treeminDepth << endl;
}
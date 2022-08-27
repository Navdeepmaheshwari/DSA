
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

int height(Node *root)
{
    if (root != NULL)
    {
        return (max(height(root->left), height(root->right)) + 1);
    }
    return 0;
}

//O(n2)
bool isBalancedNaive(Node *root)
{
    if (root == NULL)
        return true;
    int leftHeight = height(root->left);

    int rightHeight = height(root->right);
    int diff = abs(leftHeight - rightHeight);
    return ((diff <= 1) && isBalancedNaive(root->left) && isBalancedNaive(root->right));
}

//O(n)
int isBalanced(Node *root)
{
    /* if (root == NULL)
        return 0;
    int leftHeight = isBalanced(root->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = isBalanced(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;
    else
        return max(leftHeight, rightHeight) + 1; */
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
    //  root->right->right->right = new Node(60);
    bool ans = isBalancedNaive(root);
    if (ans)
    {
        cout << "Tree is Balanced" << endl;
    }
    else
    {
        cout << "Tree is not Balanced" << endl;
    }
}
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
    ? Efficient Approach 
*/
bool isBST(Node *root, int min, int max)
{
    if (root == NULL)
        return true;

    return (root->key > min && root->key < max && isBST(root->left, min, root->key) && isBST(root->right, root->key, max));
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
    int min = INT32_MIN;
    int max = INT32_MAX;
    bool ans = isBST(root, min, max);
    if (ans)
    {
        cout << "BST" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
// Conversion of Array/String to Tree
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

const int EMPTY = -1;
int ind = 0;
Node *deserialize(vector<int> &arr)
{
    if (ind == arr.size())
        return NULL;
    int val = arr[ind];
    ind++;
    if (val == EMPTY)
        return NULL;
    Node *root = new Node(val);
    root->left = deserialize(arr);
    root->right = deserialize(arr);

    return root;
}
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}
int main()
{
    /* Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80);
    root->right = new Node(30);
    root->right->right = new Node(60); */
    vector<int> arr = {10, 20, 40, -1, -1, 50, 70, -1, -1, 80, -1, -1, 30, -1, 60, -1, -1};

    Node *root = deserialize(arr);
    cout << "InOrder Traversal : ";
    inOrder(root);
}
// Conversion of Tree to Array/String
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
void serialize(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        arr.push_back(EMPTY);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left, arr);
    serialize(root->right, arr);
}
void printVector(vector<int> arr)
{
    for (int i : arr)
    {
        cout << i << " ";
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
    vector<int> arr;

    serialize(root, arr);
    printVector(arr);
}
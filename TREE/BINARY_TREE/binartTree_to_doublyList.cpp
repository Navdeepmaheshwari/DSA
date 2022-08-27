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

Node *pre = NULL;
Node *TreetoDoublyList(Node *root)
{

    if (root == NULL)
        return root;
    Node *head = TreetoDoublyList(root->left);
    if (pre == NULL)
    {
        head = root;
    }
    else
    {
        root->left = pre;
        pre->right = root;
    }
    pre = root;
    TreetoDoublyList(root->right);

    return head;
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

    Node *head = TreetoDoublyList(root);
    while (head != NULL)
    {
        cout << head->key << " ";
        head = head->right;
    }
}
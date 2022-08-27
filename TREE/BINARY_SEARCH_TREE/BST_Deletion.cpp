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
Node *getSuccessor(Node *curr)
{

    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *deletion(Node *root, int x)
{

    if (root == NULL)
        return root;
    else if (root->key < x)
        root->right = deletion(root->right, x);
    else if (root->key > x)
        root->left = deletion(root->left, x);

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *successor = getSuccessor(root);
            root->key = successor->key;
            root->right = deletion(root->right, successor->key);
        }
        return root;
    }
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
    Node *newroot = deletion(root, 50);
    inOrder(newroot);
}
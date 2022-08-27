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
    ? Time Complexities
    * O(h)--Time Complexity
    * O(1)--Auxillary Space
 */
Node *ceilBST(Node *root, int x)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == x)
        {
            return root;
        }
        else if (root->key < x)
        {
            root = root->right;
        }
        else
        {
            res = root;
            root = root->left;
        }
    }
    return res;
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

    int x = 100;
    Node *ans = ceilBST(root, x);

    cout << "Ceil of " << x << " is : " << ans->key << endl;
}
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
     Efficient solution requires only one tree traversal and theta(h) space
     In this both n1 and n2 of LCA must be present.  LCA(n1,n2)
     It doesn't give correct result if either n1 or n2 doesn't exist
*/
Node *LCAEfficient(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->key == n1 || root->key == n2)
        return root;

    Node *lca1 = LCAEfficient(root->left, n1, n2);
    Node *lca2 = LCAEfficient(root->right, n1, n2);
    if (lca1 != NULL && lca2 != NULL)
        return root;
    if (lca1 != NULL)
        return lca1;
    else
    {
        return lca2;
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);

    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    Node *ans = LCAEfficient(root, 40, 50);
    cout<<ans->key<<endl;
}
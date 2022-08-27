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

int maxlevel = 0;

bool isChildrenSum(Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;

    int sum = 0;
    if (root->left != NULL)
    {
        sum = sum + root->left->key;
    }
    if (root->right != NULL)
    {
        sum = sum + root->right->key;
    }

    return ((root->key == sum) && isChildrenSum(root->left) && isChildrenSum(root->right));
}

int main()
{
         /*
            Tree Example:
            
                20
               /  \
              8    12
             / \
            3   5

        */

    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    // root->left->right->left = new Node(70);
    // root->left->right->right = new Node(80);
    root->right = new Node(12);
    // root->right->right = new Node(60);
    bool ans = isChildrenSum(root);
    if (ans)
    {
        cout << "Tree Follows Children's Sum Property";
    }
}
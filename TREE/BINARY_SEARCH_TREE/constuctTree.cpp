
/*
Given an array arr[] of N nodes representing preorder traversal of some BST.
You have to build the exact BST from it's given preorder traversal.
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// A utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node *constructTree(int pre[], int size, int &preind, int key, int min, int max)
{
    if (preind >= size)
        return NULL;

    Node *root = NULL;
    if (key > min && key < max)
    {
        root = newNode(key);
        preind = preind + 1;

        if (preind < size)
        {

            root->left = constructTree(pre, size, preind, pre[preind], min, key);
        }
        if (preind < size)
        {

            root->right = constructTree(pre, size, preind, pre[preind], key, max);
        }
    }
    return root;
}
// Function that constructs BST from its preorder traversal.
Node *buildBST(int pre[], int size)
{
    int preind = 0;
    return constructTree(pre, size, preind, pre[0], INT_MIN, INT_MAX);
}
void printInorder(Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
int main()
{
    int pre[] = {8,5,1,7,10,12};
    int size = sizeof(pre) / sizeof(pre[0]);

    // Function call
    Node *root = buildBST(pre, size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}
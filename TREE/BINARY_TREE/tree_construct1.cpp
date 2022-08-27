// Construct a tree from given Inorder and Preorder Traversal
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

int preIndex = 0;

Node *constructTree(int in[], int pre[], int startInd, int endInd)
{
    if (startInd > endInd)
        return NULL;
    Node *root = new Node(pre[preIndex++]);
    int inIndex;

    for (int i = startInd; i <= endInd; i++)
    {
        if (in[i] == root->key)
        {
            inIndex = i;
            break;
        }
    }

    root->left = constructTree(in, pre, startInd, inIndex - 1);
    root->right = constructTree(in, pre, inIndex + 1, endInd);

    return root;
}

// Checking Tree is Correct
void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    int inorder[] = {20, 10, 40, 30, 50};
    int preorder[] = {10, 20, 30, 40, 50};
    int start = 0;
    int end = sizeof(inorder) / sizeof(inorder[0]);
    // cout<<end;
    Node *tree = constructTree(inorder, preorder, start, end-1);
    inOrder(tree);
    cout << endl;
    preOrder(tree);
}
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
    Naive solution
    Time Complexity:O(n^2)

*/
int height(Node *root)
{
    if (root != NULL)
    {
        return (max(height(root->left), height(root->right)) + 1);
    }
    return 0;
}

int diameterNaive(Node *root)
{
    if (root == NULL)
        return 0;
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameterNaive(root->left);
    int d3 = diameterNaive(root->right);

    return (max(d1, max(d2, d3)));
}

/*
    Efficient Solution
    TIme Complexity: O(n)
*/

int dia = 0;
int heightforDiameter(Node *root)
{
    if (root == NULL)
        return 0;
    int lh = heightforDiameter(root->left);
    int rh = heightforDiameter(root->right);
    dia = max(dia, 1 + lh + rh);

    return 1 + max(lh, rh);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    /* root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(70);
    root->left->right->right = new Node(80); */
    root->right = new Node(3);
    /*  root->right->right = new Node(60); */
    int treediameter = diameterNaive(root);
    cout << treediameter << endl; // O(n2)

    int height = heightforDiameter(root);
    cout << dia << endl; // O(n)
}
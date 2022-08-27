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

void vrSumRecursive(Node *root, int horizontalDis, map<int, int> &sum)
{
    if (root == NULL)
        return;
    vrSumRecursive(root->left, horizontalDis - 1, sum);
    sum[horizontalDis] += root->key;
    vrSumRecursive(root->right, horizontalDis + 1, sum);
}

void verticalSum(Node *root)
{
    map<int, int> sum;
    vrSumRecursive(root, 0, sum);

    cout << "Vertical Sum : ";
    for (auto i : sum)
    {
        cout << i.second << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(10);

    root->left = new Node(15);
    root->left->left = new Node(35);
    root->left->right = new Node(20);

    root->right = new Node(25);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    verticalSum(root);
}
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

int mxmWidth(Node *root)
{
    if (root == NULL)
        return 0;
    int res = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        res = max(count, res);

        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
    return res;
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
    int treemxmWidth = mxmWidth(root);
    cout << treemxmWidth << endl;
}
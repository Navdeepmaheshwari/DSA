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

void verticalOrderTraversal(Node *root)
{
    map<int, vector<int>> Order;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (q.empty() == false)
    {
        pair<Node *, int> p = q.front();
        Node *curr = p.first;
        int horizontalDis = p.second;
        Order[horizontalDis].push_back(curr->key);
        q.pop();

        if (curr->left != NULL)
        {
            q.push({curr->left, horizontalDis - 1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right, horizontalDis + 1});
        }
    }
cout<<"Vertical Order Traversal"<<endl;
    for (auto p : Order)
    {
        vector<int> v = p.second;
        for (int j : v)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(10);

    root->left = new Node(20);
     root->left->left = new Node(35);
     root->left->right = new Node(20);

    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    verticalOrderTraversal(root);
}

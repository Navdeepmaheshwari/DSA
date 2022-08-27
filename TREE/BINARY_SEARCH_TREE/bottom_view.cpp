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

void bottomView(Node *root)
{
    map<int, int> bottom;
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (q.empty() == false)
    {
        pair<Node *, int> p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        if (bottom.find(hd) == bottom.end())
            bottom[hd] = curr->key;
        if (bottom.find(hd) != bottom.end())
            bottom[hd] = curr->key;
        q.pop();

        if (curr->left != NULL)
        {
            q.push({curr->left, hd - 1});
        }
        if (curr->right != NULL)
        {
            q.push({curr->right, hd + 1});
        }
    }
    
    cout<<"Bottom View"<<endl;
    for (auto i : bottom)
    {
        cout << i.second << endl;
    }
    // cout << endl;
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

    bottomView(root);
}
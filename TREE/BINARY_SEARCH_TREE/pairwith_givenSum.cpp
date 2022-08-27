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

void inOrder(Node *root, vector<int> &res)
{

    if (root != NULL)
    {
        inOrder(root->left, res);
        res.push_back(root->key);
        inOrder(root->right, res);
    };
    // return res;
}
pair<int, int> findPair(vector<int> arr, int sum)
{
    pair<int, int> ans;
    int n = arr.size();
    /* for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    } */

    int first = 0, last = n - 1;

    while (first < last)
    {
        if (arr[first] + arr[last] == sum)
        {
            ans.first = arr[first];
            ans.second = arr[last];
            // ans = make_pair(arr[first], arr[last]);
            return ans;
        }
        else if (arr[first] + arr[last] > sum)
        {
            last--;
        }
        else
        {
            first++;
        }
    }
    return ans;
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

    int sum = 50;
    vector<int> traversal;
    inOrder(root, traversal);
    pair<int, int> res;
    res = findPair(traversal, sum);
    cout << "Pair are : " << res.first << " " << res.second << endl;
}
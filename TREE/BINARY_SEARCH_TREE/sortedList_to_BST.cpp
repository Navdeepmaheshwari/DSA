#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(int k)
    {
        key = k;
        left = right = NULL;
    }
};

struct ListNode
{
    int val;
    ListNode *next;
    // TreeNode *right;

    // Constructor
    ListNode(int k)
    {
        val = k;
        next = NULL;
    }
};

TreeNode *ListToBST(ListNode *start, ListNode *end)
{

    if (start == end)
        return NULL;
    ListNode *slow = start;
    ListNode *fast = start;

    while (fast != end && fast->next != end)
    {

        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    root->left = ListToBST(start, slow);
    root->right = ListToBST(slow->next, end);

    return root;
}
TreeNode *sortedListToBST(ListNode *head)
{

    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return new TreeNode(head->val);

    return ListToBST(head, NULL);
}
void inOrder(TreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main()
{
    ListNode *head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);
    TreeNode *root = sortedListToBST(head);
    inOrder(root);
    return 0;
}
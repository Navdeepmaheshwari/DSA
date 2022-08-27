#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void PrintList(Node *head)
{
    // Node *curr = head;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ========FLOYD'S CYCLE DETECTION=========
// TIME--  O(N);
// SPACE-- O(1);
bool isLoop(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // head->next->next->next->next = head->next; //connecting last node to 2nd node to make cycle
    // PrintList(head);
    bool ans = isLoop(head);
    if (ans)
    {
        cout << "Loop Present" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
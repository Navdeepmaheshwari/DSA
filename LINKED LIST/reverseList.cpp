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

// ITERATIVE SOLUTION

Node *reverseList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// RECURSIVE SOLUTION
Node *reverseListrecursive(Node *curr, Node *prev)
{
    if (curr == NULL)
        return prev;
    Node *next = curr->next;
    curr->next = prev;
    return (reverseListrecursive(next, curr));
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    //  head->next->next->next->next = new Node(50);
    PrintList(head);


    head = reverseList(head);
    PrintList(head);


    // Node *curr = head;
    // Node *prev = NULL;
    // head = reverseListrecursive(curr, prev);
    // PrintList(head);

    return 0;
}
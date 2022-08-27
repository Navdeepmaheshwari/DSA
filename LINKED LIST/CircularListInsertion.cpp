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
    if (head == NULL)
        return;

    // Method-1

    // cout << head->data << " ";
    // for (Node *p = head->next; p != head; p = p->next)
    // {
    //     cout << p->data << " ";
    // }
    // cout << endl;

    // Method-2
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);

    cout << endl;
}

// Insert at Begin
Node *InserBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;
        int t = head->data;
        head->data = temp->data;
        temp->data = t;

        return head;
    }
}

// Insert at End
Node *InsertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    else
    {
        temp->next = head->next;
        head->next = temp;

        int t = temp->data;
        temp->data = head->data;
        head->data = t;

        return temp;
    }
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Make list Circular by connecting Last Node to First
    head->next->next->next->next = head;
    PrintList(head);
    head = InserBegin(head, 5);
    PrintList(head);
    head = InsertEnd(head, 500);
    PrintList(head);
    return 0;
}
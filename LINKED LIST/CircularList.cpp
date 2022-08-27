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

    cout<<endl;
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

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
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
// Insert at Begin
Node *insertBegin(Node *head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;

    if (head->next != NULL)
    {
        head->prev = temp;
    }

    return temp;
}

// Insert at End
Node *insertEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head->next == NULL)
        return temp;
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;

    return head;
}
int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);

    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    PrintList(head);
    head = insertBegin(head, 5);
    cout << "After Insertion at Begining" << endl;
    PrintList(head);

    head = insertEnd(head, 500);
    cout << "After Insertion at End" << endl;
    PrintList(head);
}
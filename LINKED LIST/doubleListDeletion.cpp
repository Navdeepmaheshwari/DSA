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
// delete at Begin
Node *deleteBegin(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }

    else
    {
        Node *temp = head->next;
        temp->prev = NULL;
        delete (head);
        return temp;
    }
}

// delete at End
Node *deleteEnd(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->prev->next=NULL;
    delete curr;
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
    // Node *head = NULL;
    PrintList(head);
    head = deleteBegin(head);
    cout << "After deletion at Begining" << endl;
    PrintList(head);

    head = deleteEnd(head);
    cout << "After deletion at End" << endl;
    PrintList(head);
}
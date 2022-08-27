#include <bits/stdc++.h>
using namespace std;

// Defining List
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
// delete At Begining
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    else
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

// delete At End
Node *deleteLast(Node *head)
{

    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next->next != NULL)
        curr = curr->next;
    delete (curr->next);
    curr->next = NULL;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    PrintList(head);
    cout << "After Deletion at Head Node" << endl;
    head = deleteHead(head);
    PrintList(head);
    cout << "After Deletion at Last Node" << endl;
    head = deleteLast(head);
    PrintList(head);

    return 0;
}
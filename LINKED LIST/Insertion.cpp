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
// Insert At Begining
Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    // temp->data = x;
    temp->next = head;
    return temp;
}

// Insert At End
Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}

// Insert At given Position
Node *insertPos(Node *head, int pos, int x)
{
    Node *temp = new Node(x);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for (int i = 1; i <= pos - 2 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;

    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    PrintList(head);
    cout << "After Insertion at Begining" << endl;
    head = insertBegin(head, 5);
    PrintList(head);
    cout << "After Insertion at End" << endl;
    head = insertEnd(head, 50);
    PrintList(head);
    cout << "After Insertion at Position 3" << endl;
    head = insertPos(head, 3, 500);
    PrintList(head);
    return 0;
}
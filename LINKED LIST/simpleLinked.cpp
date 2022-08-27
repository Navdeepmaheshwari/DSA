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
void PrintRecursive(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    PrintRecursive(head->next);
}
// int main()
// {
//     Node *head = new Node(10);
//     Node *temp1 = new Node(20);
//     Node *temp2 = new Node(30);

//     head->next = temp1;
//     temp1->next = temp2;

//     return 0;
// }

// Another Shorter Way

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    PrintList(head);
    PrintRecursive(head);
    return 0;
}
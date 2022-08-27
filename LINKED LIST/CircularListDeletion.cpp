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

// Delete HEAD
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        int t = head->next->data;
        head->data = t;

        Node *temp = head->next;
        head->next = head->next->next;
        delete temp;
        return head;
    }
}
// delete End
Node *deleteEnd(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *curr = head;
        while (curr->next->next != head)
        {
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }
}

// Delete Kth Element
Node *deleteKth(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    if (k == 1)
    {
        return deleteHead(head);
    }
    else
    {
        Node *curr = head;
        for (int i = 0; i < k - 2; i++)
        {
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
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
    head = deleteHead(head);
    PrintList(head);
    head = deleteEnd(head);
    PrintList(head);
    head = deleteKth(head, 2);
    PrintList(head);

    return 0;
}
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
void isLoop(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            break;
        }
    }

    if (slow != fast)
        return;
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << "Before Removing LOOP fast->next is " << fast->next << endl;
    fast->next = NULL;
    cout << "After Removing LOOP fast->next become " << fast->next << endl;
    int count = 0;
    cout << "LOOP First Node " << slow->next->data << endl;
    while (slow->next != NULL)
    {
        slow = slow->next;
        cout << slow->data << endl;
        count++;
    }
    cout << "Length of Loop " << count << endl;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head->next->next->next->next = head->next; // connecting last node to 2nd node to make cycle
    // PrintList(head);
    isLoop(head);

    return 0;
}
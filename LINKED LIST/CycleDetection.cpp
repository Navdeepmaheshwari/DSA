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


//TIME--  O(N);
//SPACE-- O(N);
bool isLoop(Node *head)
{
    unordered_set<Node *> s;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        if (s.find(curr) != s.end())
            return true;
        s.insert(curr);
    }
    return false;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // head->next->next->next->next = head->next; //connecting last node to 2nd node to make cycle
    // PrintList(head);
    bool ans = isLoop(head);
    if (ans)
    {
        cout << "LOOP Present" << endl;
    }
    return 0;
}
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

void PrintList(Node *list1)
{
    // Node *curr = list1;
    while (list1 != NULL)
    {
        cout << list1->data << " ";
        list1 = list1->next;
    }
    cout << endl;
}

Node *mergeList(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    Node *head = NULL, *tail = NULL;
    if (list1->data <= list2->data)
    {
        head = tail = list1;
        list1 = list1->next;
    }
    else
    {
        head = tail = list2;
        list2 = list2->next;
    }

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            tail = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            tail = list2;
            list2 = list2->next;
        }
    }

    if (list1 == NULL)
    {
        tail->next = list2;
    }
    else
    {
        tail->next = list1;
    }

    return head;
}

int main()
{
    Node *list1 = new Node(10);
    list1->next = new Node(20);
    list1->next->next = new Node(30);
    list1->next->next->next = new Node(40);

    Node *list2 = new Node(1);
    list2->next = new Node(12);
    list2->next->next = new Node(23);
    list2->next->next->next = new Node(45);

    Node *newlist = mergeList(list1, list2);
    PrintList(newlist);
    return 0;
}
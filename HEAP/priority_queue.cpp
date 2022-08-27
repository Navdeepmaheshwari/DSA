#include <bits/stdc++.h>
using namespace std;

int main()
{
    // TODO Max Heap
    //? By default, C++ creates a max-heap for priority queue.
    priority_queue<int> pq;
    pq.push(10);
    pq.push(2);
    pq.push(50);
    pq.push(11);

    /*  cout << "size of queue is : " << pq.size() << endl;
     cout << "top element of queue is : " << pq.top() << endl; */
    cout << "Max Heap : ";
    while (pq.empty() != true)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    // TODO Min Heap
    priority_queue<int, vector<int>, greater<int>> g;
    g.push(10);
    g.push(2);
    g.push(50);
    g.push(11);

    /*  cout << "size of queue is : " << pq.size() << endl;
     cout << "top element of queue is : " << pq.top() << endl; */
    cout << "Min Heap : ";
    while (g.empty() != true)
    {
        cout << g.top() << " ";
        g.pop();
    }
    return 0;


    
}
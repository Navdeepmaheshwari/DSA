#include <bits/stdc++.h>
using namespace std;

// TODO  using MAX HEAP
//*     Time complexity: O(n + k*log(n))
void printKLargest(int arr[], int n, int k)
{

    priority_queue<int> pq(arr, arr + n);
    while (k--)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

// Todo  using MIN HEAP
//*     Time complexity: O(k + (n-k)*log(k))

void kLargest(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + k);
    for (int i = k; i < n; i++)
    {
        if (arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while (pq.empty() != true)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}
int main()
{
    int arr[] = {1, 12, 5, 111, 200, 1000, 10, 9, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    printKLargest(arr, n, k);
    cout << endl;
    kLargest(arr, n, k);
    return 0;
}
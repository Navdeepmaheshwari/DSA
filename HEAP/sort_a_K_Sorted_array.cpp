#include <bits/stdc++.h>
using namespace std;

void sortK(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; //* min heap
    for (int i = 0; i <= k; i++)
    {
        pq.push(arr[i]);
    }

    int index = 0;
    for (int i = k + 1; i < n; i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while (pq.empty() == false)
    {
        arr[index++] = pq.top();
        pq.pop();
    }
}
int main()
{
    int arr[] = {9, 8, 7, 19, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    sortK(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
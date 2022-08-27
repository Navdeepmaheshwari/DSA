#include <bits/stdc++.h>
using namespace std;

int mxmCount(int arr[], int n, int sum)
{

    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    int res = 0;
    while (pq.top() <= sum)
    {
        res++;
        sum -= pq.top();
        pq.pop();
    }
    return res;
}

int main()
{
    int arr[] = {1, 12, 5, 111, 200, 1000, 10, 9, 12, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 50;
    int count = mxmCount(arr, n, sum);
    cout << count << endl;
    return 0;
}
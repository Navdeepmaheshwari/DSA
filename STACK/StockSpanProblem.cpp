#include <bits/stdc++.h>
using namespace std;

// Naive Solution
// Time--O(n2)
// Space--O(1)
void Span(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--)
        {
            span++;
        }
        cout << span << " ";
    }
    cout << endl;
}
// Efficient Solution
// Time--theta(n)
// Space--O(n)
void printSpan(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout << "1 ";

    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        int span = s.empty() ? i  : i - s.top();
        cout << span << " ";
        s.push(i);
    }
    cout << endl;
}

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Span(arr, n);
    printSpan(arr, n);
}
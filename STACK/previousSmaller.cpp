#include <bits/stdc++.h>
using namespace std;


// EFFICEINT SOLUTION
// Time--O(n)
// Space--O()
void printPrevSmallerE(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && s.top() >= arr[i])
        {
            s.pop();
        }

        int prevSmaller = s.empty() ? -1 : s.top();
        cout << prevSmaller << " ";
        s.push(arr[i]);
    }
}
int main()
{
    int arr[] = {1, 5, 0, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printPrevSmallerE(arr, n);
}
#include <bits/stdc++.h>
using namespace std;
// Time-O(n);
// Space-O(n);
bool subarraySum(int arr[], int n, int sum)
{
    unordered_set<int> num;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];

        if ((prefix_sum) == sum)
        {
            return true;
        }
        if (num.find(prefix_sum - sum) != num.end())
        {
            return true;
        }
        num.insert(prefix_sum);
    }

    cout << endl;
    return false;
}
int main()
{
    int arr[] = {5, 8, 6, 13, 3, -1};
    int sum = 22;
    int n = sizeof(arr) / sizeof(arr[0]);
    bool ans = subarraySum(arr, n, sum);
    cout << ans << endl;
} 
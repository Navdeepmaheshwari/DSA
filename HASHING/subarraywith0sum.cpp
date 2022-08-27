#include <bits/stdc++.h>
using namespace std;
//Time-O(n);
//Space-O(n);
bool subarrayZero(int arr[], int n)
{
    unordered_set<int> num;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];

        if (num.find(prefix_sum) != num.end())
        {
            return true;
        }
        if ((prefix_sum) == 0)
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
    int arr[] = {-3, 4, -3, -1, 1};

    int n = sizeof(arr) / sizeof(arr[0]);
    bool ans = subarrayZero(arr, n);
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;

int minCoins(int arr[], int n, int amount)
{

    sort(arr, arr + n, greater<int>());
    int res = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] <= amount)
        {
            int c = floor(amount / arr[i]);
            res = res + c;
            amount = amount - c * arr[i];
        }

        if (amount == 0)
            break;
    }
    return res;
}

int main()
{
    int coins[] = {10, 5, 2, 1};
    int n = sizeof(coins) / sizeof(coins[0]);

    int amount = 107;
    int count = minCoins(coins, n, amount);
    cout << count << endl;

    return 0;
}
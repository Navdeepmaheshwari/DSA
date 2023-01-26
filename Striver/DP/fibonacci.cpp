#include <bits/stdc++.h>
using namespace std;

/*
! Memoization Method
* TC-O(N)
* SC-O(N)+O(N)
*/
int fibo(int n, vector<int> &dp)
{
    if (n < 2)
        return n;

    // DP check condition <--Step-3
    if (dp[n] != -1)
        return dp[n];

    // before returing store result in dp <--Step-2
    return dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
}

/*
! Tabulation Method
* TC-O(N)
* SC-O(N)
*/
int fibo2(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

/*
! Space Optimization Method
* TC-O(N)
* SC-1
*/
int fiboOptimise(int n)
{
    //* we only need two previous values to find current value so make 2 pointers
    int prev1 = 1, prev2 = 0;

    for (int i = 2; i <= n; i++)
    {

        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main()
{
    int n = 15;

    // Creating DP vector of n+1 size and storing -1 in it  <--Step-1
    vector<int> dp(n + 1, -1);

    int ans1 = fibo(n, dp); //* using dp
    int ans2 = fibo2(n);
    int ans3 = fiboOptimise(n); // *Space Optimization

    cout << ans1 << " " << ans2;

    return 0;
}
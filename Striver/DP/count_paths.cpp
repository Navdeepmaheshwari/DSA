/*
The task is to count all the possible paths from top left to bottom right of a m X n matrix with the constraints that from each cell you can either move only to right or down.
*/

#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
{
    // Base conditionec
    if (i == m || j == n)
        return 0;
    if (i == m - 1 && j == n - 1)
        return 1;

    // if dp[i][j] isn't calculated then only perform
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans1 = solve(i + 1, j, m, n, dp);
    int ans2 = solve(i, j + 1, m, n, dp);

    return dp[i][j] = (ans1 + ans2) % mod; // store res in dp
}

long long int numberOfPaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1)); // 2D DP Matrix
    return solve(0, 0, m, n, dp);
}
int main()
{
    int m = 3, n = 3;
    long long int ans = numberOfPaths(m, n);
    cout << ans << endl;
    return 0;
}
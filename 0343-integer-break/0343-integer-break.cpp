class Solution {
public:
     int maxProduct(int n, vector<int>& dp) {
        if (n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        int maxProd = 0;
        for (int i = 1; i < n; ++i) {
            maxProd = max(maxProd, max(i * (n - i), i * maxProduct(n - i, dp)));
        }
        dp[n] = maxProd;
        return maxProd;
    }
    int integerBreak(int n) {
        vector<int> dp(n + 1, -1);
        return maxProduct(n, dp);
    }
};
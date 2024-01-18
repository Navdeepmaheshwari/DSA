class Solution {
public:
    
    int totalWays(int n,vector<int> &dp){
        if(n<0)return 0;
        
        if(n<2)return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= totalWays(n-1,dp)+totalWays(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans=totalWays(n,dp);
        
        return ans;
    }
};
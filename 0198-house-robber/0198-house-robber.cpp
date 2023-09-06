class Solution {
public:
    int solve(int ind,vector<int>& nums,int n,vector<int>&dp){
        if(ind>=n){
            return 0;
        }
        if(ind==n-1)return nums[n-1];
        if(dp[ind]!=-1)return dp[ind];
        return dp[ind]=max(nums[ind]+solve(ind+2,nums,n,dp),solve(ind+1,nums,n,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
    }
};
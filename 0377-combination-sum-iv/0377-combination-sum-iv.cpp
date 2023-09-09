class Solution {
public:
    int solve(int i,vector<int>& nums, int target,int n,vector<int>&dp){
        if(target<0)return 0;
        if(target==0)return 1;
        if(dp[target]!=-1)
            return dp[target];
      
        int ans=0;
        for(int j=0;j<n;j++){
            if(target>=nums[j]){
                ans+=solve(j,nums,target-nums[j],n,dp);
            }
        }
        
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return solve(0,nums,target,n,dp);
    }
};
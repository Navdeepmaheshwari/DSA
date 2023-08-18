class Solution {
public:
    bool solve(int i,vector<int>&nums,int n, vector<int>&dp){
        //base case
        if(i==n-1){
            return true;
        }
        if(dp[i]!=-1)return dp[i];
        
        bool isPossible=false;
        int maxx=nums[i];
        
        for(int k=i+1;k<=min(n-1,i+maxx);k++){
            
            isPossible=isPossible||solve(k,nums,n,dp);
        }
        
        return dp[i]=isPossible;
    }
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
    }
};
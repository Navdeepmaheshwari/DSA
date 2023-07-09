class Solution {
public:
    int jumps(int ind,vector<int>& nums, int target,int neg,int n, vector<int>&dp){
        
        if(ind==n-1)return 0;
        int ans=INT_MIN;
        if(dp[ind]!=-1)return dp[ind];
        for(int j=ind+1;j<n;j++){
            int diff=nums[j]-nums[ind];
            if(diff>=neg&&diff<=target){
              ans=max(ans,1+jumps(j,nums,target,neg,n,dp));
            }
        }
        
        return dp[ind]= ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        
        int n=nums.size();
        int neg=target*-1;
        vector<int>dp(n,-1);
        int res= jumps(0,nums,target,neg,n,dp);
        if(res<=0)return -1;
        return res;
        
        
    }
};
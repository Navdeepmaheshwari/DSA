class Solution {
public:
int solve(int ind,vector<int>& nums, unordered_map<int,int>&mp,int n,vector<int>&dp){
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        
        //not pick
        int notPick=solve(ind+1,nums,mp,n,dp);
        
        //pick
        int pick =(mp[nums[ind]] * nums[ind]) + solve(upper_bound(nums.begin(),nums.end(),nums[ind]+1)-nums.begin(),nums,mp,n,dp);
       
        
        return dp[ind]=max(pick,notPick);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        
        sort(nums.begin(),nums.end());
        vector<int>dp(n,-1);
        return solve(0,nums,mp,n,dp);
    }
};
class Solution {
public:
    bool solve(int ind,vector<int>& nums,int n, vector<int>&dp){
        
        if(ind>=n)return true;
        if(dp[ind]!=-1)return dp[ind];
        
        //1st Condition
        if(ind+1<n&&nums[ind]==nums[ind+1]){
            
           if(solve(ind+2,nums,n,dp)) return true;
            
            //2nd Condition
            if(ind+2<n&&nums[ind]==nums[ind+2]){
                if(solve(ind+3,nums,n,dp)) return true;
            }
        }
        
        //3rd condition
        if(ind+2<n && nums[ind]==nums[ind+1]-1 && nums[ind]==nums[ind+2]-2)                   {
            if(solve(ind+3,nums,n,dp)) return true;
        }
        
        
       return dp[ind]=false;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
       return solve(0,nums,n,dp);
    }
};
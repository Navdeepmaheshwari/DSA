class Solution {
public:
    long long solve(int i,int x, int parity,vector<int>&nums,vector<vector<long long>>&dp,int n){
        
        if(i>=n)return 0;
        if(dp[i][parity]!=-1)return dp[i][parity];
        
        long long nottake=0,take=0;
                
        //not take
        nottake=solve(i+1,x,parity,nums,dp,n);
        
        //take
        if(nums[i]%2==parity){
            take=nums[i]+solve(i+1,x,parity,nums,dp,n);
        }
        else{
          take=nums[i]-x+solve(i+1,x,nums[i]%2,nums,dp,n);  
        }
        return dp[i][parity]=max(take,nottake);
}
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        int parity=nums[0]%2==0?0:1;//chk even /odd 
        return nums[0]+solve(1,x,parity,nums,dp,n);
    }
};
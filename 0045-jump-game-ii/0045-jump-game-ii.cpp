class Solution {
public:
     int solve(int i,vector<int>&nums,int n, vector<int>&dp){
        //base case
        if(i==n-1){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        
        int cnt=1e9;
        int maxx=nums[i];
        
        for(int k=i+1;k<=min(n-1,i+maxx);k++){
            
           int currcnt=1+solve(k,nums,n,dp);
            cnt=min(cnt,currcnt);
        }
        
        return dp[i]=cnt;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
    }
};
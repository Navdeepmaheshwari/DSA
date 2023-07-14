class Solution {
public:
    int f(int curInd,int prevInd,vector<int>&nums,int n,vector<vector<int>>&dp){
        //Base Case
        if(curInd==n)return 0;
        int len=0;
        
        if(dp[curInd][prevInd+1]!=-1)return dp[curInd][prevInd+1];
        //not Take
        int notTake=0+f(curInd+1,prevInd,nums,n,dp);
        
        //Take
        int take=0;
        if(prevInd==-1||nums[prevInd]<nums[curInd]){
           take=1+f(curInd+1,curInd,nums,n,dp);
        }
        len=max(take,notTake);
        return dp[curInd][prevInd+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        //coordinate chnage apply for prevInd because we cant store at index -1 in vector  
        vector<vector<int>>dp(n,vector<int>(n+1,-1)); 
        return f(0,-1,nums,n,dp);
    }
};
class Solution {
public:
//     int f(int curInd,int prevInd,vector<int>&nums,int n,vector<vector<int>>&dp){
//         //Base Case
//         if(curInd==n)return 0;
        
//         int len=0;
        
//         if(dp[curInd][prevInd+1]!=-1)return dp[curInd][prevInd+1];
        
//         //not Take
//         len=0+f(curInd+1,prevInd,nums,n,dp);
        
//         //Take
//         if(prevInd==-1||nums[prevInd]<nums[curInd]){
//            len=max(len,1+f(curInd+1,curInd,nums,n,dp));
//         }
//         return dp[curInd][prevInd+1]=len;
//     }
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        // //coordinate chnage apply for prevInd because we cant store at index -1 in vector  
        // vector<vector<int>>dp(n,vector<int>(n+1,-1)); 
        // return f(0,-1,nums,n,dp);
        
        
        //Tabulation
         vector<vector<int>>dp(n+1,vector<int>(n+1,0)); 
        
        for(int curInd=n-1;curInd>=0;curInd--){
            for(int prevInd=curInd-1;prevInd>=-1;prevInd--){
                
     //in dp second parameter always add +1 because of coordinate shifting

                int len=0;
                len=0+dp[curInd+1][prevInd+1];
                
                if(prevInd==-1||nums[prevInd]<nums[curInd]){
                    len=max(len,1+dp[curInd+1][curInd+1]);
                }
                
                dp[curInd][prevInd+1]=len;
            }
        }
        return dp[0][-1+1];
        

    }
};
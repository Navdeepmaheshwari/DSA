class Solution {
public:
    int MOD=1e9+7;
    int solve(int i,int steps,int len, vector<vector<int>>&dp){
        if(steps==0&&i==0){
            return 1;
        }
        
        if(i<0||i>=len||steps==0||i>steps)return 0;
       
        if(dp[steps][i]!=-1)return dp[steps][i];
        //3case
        long long stay=solve(i,steps-1,len,dp);
        long long right=solve(i+1,steps-1,len,dp);
        long long left=solve(i-1,steps-1,len,dp);
        
        return dp[steps][i]= (stay+left+right)%MOD;
    }
    int numWays(int steps, int len) {
        vector<vector<int>>dp(steps+1,vector<int>((steps)/2 + 1,-1));
        return solve(0,steps,len,dp);
    }
};
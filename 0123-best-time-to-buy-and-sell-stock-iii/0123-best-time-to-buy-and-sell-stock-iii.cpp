class Solution {
public:
 int f(int i,int buy,vector<int>& p,vector<vector<vector<int>>>&dp,int n,int cnt){
        
        if(i==n||cnt==0)return 0;
        
        if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];
        int profit=0;
        if(buy){
            profit=max((-p[i]+f(i+1,0,p,dp,n,cnt)),0+f(i+1,1,p,dp,n,cnt));
        }
        else{
            profit=max((p[i]+f(i+1,1,p,dp,n,cnt-1)),0+f(i+1,0,p,dp,n,cnt));
        }
        return dp[i][buy][cnt]=profit;
    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int maxTransactions=2;
        //3D-DP
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(maxTransactions+1,-1)));
        return f(0,1,p,dp,n,maxTransactions);
    }
};
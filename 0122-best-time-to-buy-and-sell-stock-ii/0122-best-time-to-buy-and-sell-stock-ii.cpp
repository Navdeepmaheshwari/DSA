class Solution {
public:
//     int f(int i,int buy,vector<int>& p,vector<vector<int>>&dp,int n){
        
//         if(i==n)return 0;
        
//         if(dp[i][buy]!=-1)return dp[i][buy];
//         int profit=0;
//         if(buy){
//             profit=max((-p[i]+f(i+1,0,p,dp,n)),0+f(i+1,1,p,dp,n));
//         }
//         else{
//             profit=max((p[i]+f(i+1,1,p,dp,n)),0+f(i+1,0,p,dp,n));
//         }
//         return dp[i][buy]=profit;
//     }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return f(0,1,p,dp,n);
        
        //Tabulations
         vector<vector<int>> dp( n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;// Out of bound
        for( int ind=n-1; ind>=0; ind-- ){
            for( int buy=0; buy<=1; buy++ ){
                int profit = 0;
                if( buy )//means we can buy, here two cases exist whether we want to buy or not
                    profit = max( -p[ind]+ dp[ind+1][0], dp[ind+1][1] );
                else
                    profit = max( p[ind]+dp[ind+1][1] , dp[ind+1][0]);
                
                dp[ind][buy] = profit;   
            }
        }
        return dp[0][1];
    }
};
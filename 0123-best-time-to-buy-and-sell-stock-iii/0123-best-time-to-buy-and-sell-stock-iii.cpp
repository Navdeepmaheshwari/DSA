class Solution {
public:
//  int f(int i,int buy,vector<int>& p,vector<vector<vector<int>>>&dp,int n,int cnt){
        
//         if(i==n||cnt==0)return 0;
        
//         if(dp[i][buy][cnt]!=-1)return dp[i][buy][cnt];
//         int profit=0;
//         if(buy){
//             profit=max((-p[i]+f(i+1,0,p,dp,n,cnt)),0+f(i+1,1,p,dp,n,cnt));
//         }
//         else{
//             profit=max((p[i]+f(i+1,1,p,dp,n,cnt-1)),0+f(i+1,0,p,dp,n,cnt));
//         }
//         return dp[i][buy][cnt]=profit;
//     }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int maxTransactions=2;
        //3D-DP
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(maxTransactions+1,-1)));
        // return f(0,1,p,dp,n,maxTransactions);
        
        
        //Tabulation
   vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(maxTransactions+1,0)));
        
        //Base case 
        //as base case in recursion return 0 and in tabulation we initialize dp with 0 
        //so need to write;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=1;cnt<=maxTransactions;cnt++){//for cnt=0 always 0,so start from cnt=1
                    
                int profit = 0;
                if( buy )//means we can buy, here two cases exist whether we want to buy or not
                    profit = max( -p[ind]+ dp[ind+1][0][cnt], dp[ind+1][1][cnt] );
                else
                    profit = max( p[ind]+dp[ind+1][1][cnt-1] , dp[ind+1][0][cnt]);
                
                dp[ind][buy][cnt] = profit; 
                    
                }
            }
        }
        return dp[0][1][maxTransactions];

    }
};
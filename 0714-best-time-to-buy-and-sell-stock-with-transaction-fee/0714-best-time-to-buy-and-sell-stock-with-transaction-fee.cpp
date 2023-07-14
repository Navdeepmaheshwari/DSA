class Solution {
public:
//     int f(int ind,int buy, vector<int>&p,int n,int fee, vector<vector<int>>&dp){
        
//         if(ind>=n){
//             return 0;
//         }
//         if(dp[ind][buy]!=-1)return dp[ind][buy];
//         int profit=0;
//         if(buy){
//             profit=max(-p[ind]+f(ind+1,0,p,n,fee,dp), 0+f(ind+1,1,p,n,fee,dp));
//         }
//         else{
//             //stock sold only then fee applicable
//             profit=max(p[ind]-fee+f(ind+1,1,p,n,fee,dp),0+f(ind+1,0,p,n,fee,dp));
//         }
//         return dp[ind][buy]=profit;
//     }
    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return f(0,1,p,n,fee,dp);
        
        
          //Tabulation
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            
            for(int buy=0;buy<=1;buy++){
                
                int profit=0;
                if(buy){
                    
                    profit=max(-p[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                }
                else{
                    //stock sold only then fee applicable
                    profit=max(p[ind]-fee+dp[ind+1][1],0+dp[ind+1][0]);
                }
                
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};
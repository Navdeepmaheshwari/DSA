class Solution {
public:
    int f(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        
        if(ind==0){
            
            if(amount%coins[0]==0)return amount/coins[0];
            return 1e9;
        }
        
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        
        int notTake=f(ind-1,amount,coins,dp);
        int take=INT_MAX;
        
        if(coins[ind]<=amount){
            take=1+f(ind,amount-coins[ind],coins,dp);
        }
        
        return dp[ind][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
      int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // int ans=f(n-1,amount,coins,dp);
        // if(ans>=1e9)return -1;
        // return ans;
        
        
          
        // Tabulation
         vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int target=0;target<=amount;target++){
           if(target%coins[0]==0)dp[0][target]=target/coins[0];
            else dp[0][target]=1e9;
        }
        
        for(int ind=1;ind<n;ind++){
            
            for(int target=0;target<=amount;target++){
                
                int notTake=0+dp[ind-1][target];
                int take=INT_MAX;

                if(coins[ind]<=target){
                    take=1+dp[ind][target-coins[ind]];
                }
                
                dp[ind][target]=min(notTake,take);
                
            }
        }
        int ans= dp[n-1][amount];
    if(ans>=1e9)return -1;
        return ans;
    }
};
class Solution {
public:
    bool isPossible(int ind,int prevJump,vector<int>& stones,int n, vector<vector<int>>&dp){

        if(ind>=n||ind<0)return false;
        if(ind==n-1)return true;
        
        if(dp[ind][prevJump]!=-1)return dp[ind][prevJump];
        
        int curr=stones[ind];
        bool can=false;
        for(int k=-1;k<=1;k++){
            int jump=prevJump+k;
            for(int j=ind+1;j<n;j++){
                
                if(curr+jump==stones[j]){
                   can=can|| isPossible(j,jump,stones,n,dp);
                }
               
            }
        }
        return dp[ind][prevJump]=can;
        
       
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        
        if(stones[1]-stones[0]>1)
            return false;
        
        if(stones.size()==2)
            return (stones[1]-stones[0]==1);
        
        vector<vector<int>> dp(2001, vector<int> (2001, -1));
        return isPossible(0,0,stones,n,dp);
    }
};
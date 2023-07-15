class Solution {
public:
    int solve(int ind,vector<vector<int>>& events, int k,int n, vector<vector<int>>&dp){
        
        if(k==0||ind==n)return 0;
        if(dp[ind][k]!=-1)return dp[ind][k];
        int val=0;
        //not take
        val=0+solve(ind+1,events,k,n,dp);
        
        //take
        int i;
        for(i=ind+1;i<n;i++){
            if(events[i][0]>events[ind][1]){
                break;
            }
        }
        val=max(val,events[ind][2]+solve(i,events,k-1,n,dp));
        
        return dp[ind][k]=val;
        
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(0,events,k,n,dp);
    }
};
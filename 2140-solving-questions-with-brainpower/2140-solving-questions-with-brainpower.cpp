class Solution {
public:
    long long solve(int ind,vector<vector<int>>& que,int n,vector<long long>&dp){
        
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        // if we not pick ind
       long long notpick=solve(ind+1,que,n,dp);
        
        //if we pick ind
       long long pick=que[ind][0]+solve(ind+que[ind][1]+1,que,n,dp);
        
        // cout<<pick<<" "<<notpick<<endl;
        return dp[ind]=max(pick,notpick); 
    }
    long long mostPoints(vector<vector<int>>& que) {
        int n=que.size();
        vector<long long>dp(n,-1);
        return solve(0,que,n,dp);
    }
};
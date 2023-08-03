class Solution {
public:
  int mod=1e9+7;
    int solve(string&s,int i, vector<int>&dp){
        
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        int cnt=3;
        if(s[i]=='7'||s[i]=='9')cnt=4;
        int ans=0;
        
        for(int j=i;j<i+cnt&&j<s.size();j++){
            
            if(s[j]==s[i]){
                ans=(ans+solve(s,j+1,dp))%mod;
            }
            else
                break;
        }
        return dp[i]=ans;
        
    }
    int countTexts(string pressedKeys) {
        int n=pressedKeys.size();
        vector<int>dp(n,-1);
        return solve(pressedKeys,0,dp);
    }
};
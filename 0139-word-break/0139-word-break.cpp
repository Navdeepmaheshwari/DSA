class Solution {
public:
    bool solve(int i,string s,  unordered_set<string>&st,vector<int>&dp){
        if(i==s.size())return true;
        if(dp[i]!=-1)return dp[i];
        for(int j=i;j<s.size();j++){
            
            if((st.find(s.substr(i,j-i+1))!=st.end()) &&  solve(j+1,s,st,dp) ){
               dp[i]=true;
               return true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& dict) {
        int n=s.size();
        vector<int>dp(n+1,-1);
         unordered_set<string>st(dict.begin(), dict.end());
        return solve(0,s,st,dp);
    }
};
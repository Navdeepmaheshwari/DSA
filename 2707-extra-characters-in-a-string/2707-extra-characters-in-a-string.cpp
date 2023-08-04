class Solution {
public:
    int solve(int i,string&s, unordered_set<string>&st,vector<int>&dp){
        if(i==s.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        
        string temp = "";
        for(int j=i;j<s.size();j++){
            
            temp.push_back(s[j]);
            if(st.find(temp)!=st.end()){
                ans=min(ans,0+solve(j+1,s,st,dp));
            }else{
                ans=min(ans,j-i+1+solve(j+1,s,st,dp));
            }
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dict) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        unordered_set<string>st(dict.begin(), dict.end());
        return solve(0,s,st,dp);
    }
};
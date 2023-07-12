class Solution {
public:
    bool f(int i,int j,string&str,string&pattern, vector<vector<int>>&dp){
        //Base Case
        if(i<0&&j<0)return true; //both pattern and string exhaust
        if(j<0&&i>=0)return false; //pattern exhaust string left
        
        //string exhaust pattern left 
        if(i<0&&j>=0){
            //left pattern must be contain all '*'
            for(int k=0;k<=j;k++){
                if(pattern[k]!='*')return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        //match or '?'        
        if(str[i]==pattern[j]||pattern[j]=='?'){
            return dp[i][j]= f(i-1,j-1,str,pattern,dp);
        }
        
        //'*'
        if(pattern[j]=='*'){
            bool a= f(i-1,j,str,pattern,dp); //match * with str[i] and reduce i
            bool b=f(i,j-1,str,pattern,dp); //or  doesn't match, reduce j
                 
            return dp[i][j]= a|b;
        }
        
        //not match
        return dp[i][j]= false;
    }
    bool isMatch(string str, string pattern) {
        
        int n=str.size(),m=pattern.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return f(n-1,m-1,str,pattern,dp);
    }
};
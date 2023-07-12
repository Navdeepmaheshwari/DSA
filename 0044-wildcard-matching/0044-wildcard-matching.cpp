class Solution {
public:
//     bool f(int i,int j,string&str,string&pattern, vector<vector<int>>&dp){
//         //Base Case
//         if(i==0&&j==0)return true; //both pattern and string exhaust
//         if(j==0&&i>0)return false; //pattern exhaust string left
        
//         //string exhaust pattern left 
//         if(i==0&&j>0){
//             //left pattern must be contain all '*'
//             for(int k=1;k<=j;k++){
//                 if(pattern[k-1]!='*')return false;
//             }
//             return true;
//         }
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         //match or '?'        
//         if(str[i-1]==pattern[j-1]||pattern[j-1]=='?'){
//             return dp[i][j]= f(i-1,j-1,str,pattern,dp);
//         }
        
//         //'*'
//         if(pattern[j-1]=='*'){
//             bool a= f(i-1,j,str,pattern,dp); //match * with str[i] and reduce i
//             bool b=f(i,j-1,str,pattern,dp); //or  doesn't match, reduce j
                 
//             return dp[i][j]= a|b;
//         }
        
//         //not match
//         return dp[i][j]= false;
//     }
    bool isMatch(string str, string pattern) {
        
        int n=str.size(),m=pattern.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(n,m,str,pattern,dp);
        
        //Tabulation
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        
        for(int i=1;i<=n;i++){
            dp[i][0]=false;
        }
        
        for(int j=1;j<=m;j++){
          dp[0][j]=dp[0][j-1]&&pattern[j-1]=='*';
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               
                if(str[i-1]==pattern[j-1]||pattern[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pattern[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] | dp[i][j-1];
                }
                else dp[i][j]=false;
            }
        }
        return dp[n][m];

    }
};
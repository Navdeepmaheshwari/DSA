class Solution {
public:
//     int f(int i,int j,string&s1,string&s2,vector<vector<int>>&dp){
//         //Base Case
//         if(i==0){
//             int sum=0;
//             while(j>0){
//                 sum+=s2[j-1];
//                 j--;
//             }
//             return sum;
//         }
        
//         if(j==0){
//             int sum=0;
//             while(i>0){
//                 sum+=s1[i-1];
//                 i--;
//             }
//             return sum;
//         }
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         //mattch 
//         if(s1[i-1]==s2[j-1]){
//             return dp[i][j]= 0+f(i-1,j-1,s1,s2,dp);
//         }
        
//         //not match
        
//         return dp[i][j]=min(s1[i-1]+f(i-1,j,s1,s2,dp),s2[j-1]+f(i,j-1,s1,s2,dp));
        
//     }
    int minimumDeleteSum(string s1, string s2) {
        
        int n=s1.size(),m=s2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(n,m,s1,s2,dp);
        
        //Tabulation
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=1;j<=m;j++){
            dp[0][j]=dp[0][j-1]+s2[j-1];
        }
        
        for(int i=1;i<=n;i++){   
           dp[i][0]=dp[i-1][0]+s1[i-1];
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=0+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(s1[i-1]+dp[i-1][j],s2[j-1]+dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        

    }
};
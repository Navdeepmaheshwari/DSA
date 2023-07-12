class Solution {
public:
//     int f(int i,int j,string&w1,string&w2,vector<vector<int>>&dp){
        
//         //Base Case
//         if(i==0)return j; //j+1 insert operation
        
//         if(j==0)return i; //i+1 delete operations
        
//         if(dp[i][j]!=-1)return dp[i][j];
    
//         //match 
//         if(w1[i-1]==w2[j-1]){
//             return dp[i][j]= 0+f(i-1,j-1,w1,w2,dp);
//         }

//         //not match-3operations
//         int op1=1+f(i,j-1,w1,w2,dp); //insert Operation
//         int op2=1+f(i-1,j,w1,w2,dp); //Delete Operation
//         int op3=1+f(i-1,j-1,w1,w2,dp);  //Replace Operation
        
//         return dp[i][j]= min({op1,op2,op3});
//     }
    int minDistance(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(n,m,w1,w2,dp);
        
        //TABULATION
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int j=0;j<=m;j++)dp[0][j]=j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(w1[i-1]==w2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int op1=1+dp[i][j-1]; //insert Operation
                    int op2=1+dp[i-1][j]; //Delete Operation
                    int op3=1+dp[i-1][j-1];  //Replace Operation 
                    
                    dp[i][j]=min({op1,op2,op3});
                }
            }
        }
        return dp[n][m];

    }
};
class Solution {
public:
    int f(int i,int j,string&w1,string&w2,vector<vector<int>>&dp){
        
        //Base Case
        if(i<0)return j+1; //j+1 insert operation
        
        if(j<0)return i+1; //i+1 delete operations
        
        if(dp[i][j]!=-1)return dp[i][j];
    
        //match 
        if(w1[i]==w2[j]){
            return dp[i][j]= 0+f(i-1,j-1,w1,w2,dp);
        }
        
        //not match-3operations
        int op1=1+f(i,j-1,w1,w2,dp); //insert Operation
        int op2=1+f(i-1,j,w1,w2,dp); //Delete Operation
        int op3=1+f(i-1,j-1,w1,w2,dp);  //Replace Operation
        
        return dp[i][j]= min({op1,op2,op3});
    }
    int minDistance(string w1, string w2) {
        int n=w1.size(),m=w2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,w1,w2,dp);
    }
};
class Solution {
public:
    bool solve(int i1,int i2,int i3,string s1, string s2, string s3,int n1,int n2 ,int n3,vector<vector<int>>&dp)     {
        //base case
        if(i3==n3)return true;
        if(dp[i1][i2]!=-1)return dp[i1][i2];
        if(i1==n1&&s2[i2]!=s3[i3]){
            return false;
        }
        if(i2==n2&&s1[i1]!=s3[i3]){
            return false;
        }
        
        if(s1[i1]!=s3[i3]&&s2[i2]!=s3[i3])
        {
            return false;
        }  
        
        
        bool ans=false;
       
        if(s1[i1]==s3[i3]&&s2[i2]==s3[i3]){
          ans=ans||solve(i1+1,i2,i3+1,s1,s2,s3,n1,n2,n3,dp)
              || solve(i1,i2+1,i3+1,s1,s2,s3,n1,n2,n3,dp);
        }
        else if(s1[i1]==s3[i3]){
            ans=ans||solve(i1+1,i2,i3+1,s1,s2,s3,n1,n2,n3,dp);
        }
        else if(s2[i2]==s3[i3]){
             ans=ans||solve(i1,i2+1,i3+1,s1,s2,s3,n1,n2,n3,dp);
        }
        
      return dp[i1][i2]=ans;  
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        
        if(n1+n2!=n3)return false;
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return solve(0,0,0,s1,s2,s3,n1,n2,n3,dp);
    }
};
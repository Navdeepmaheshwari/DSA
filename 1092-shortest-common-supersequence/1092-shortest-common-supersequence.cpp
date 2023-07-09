class Solution {
public:
    int lcs(string s1,string s2 ,int n,int m,vector<vector<int>>&dp){
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        
        
        for(int ind1=1;ind1<=n;ind1++){  
            for(int ind2=1;ind2<=m;ind2++){   
                
                if(s1[ind1-1]==s2[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        return dp[n][m];
       
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        //use lcs to finding the length and printing the sequence using dp matrix
        int si=lcs(s1,s2,n,m,dp); 
        cout<<si<<endl;
        
        int len=n+m-si;//shortest Common Supersequence length
        
        string ans="";
        //traversing the 2D Dp for the supersequence;
        int i=n,j=m;
        while(i>0&&j>0){
            
            //string char equal
            if(s1[i-1]==s2[j-1]){
                
                ans+=s1[i-1];
                i--;
                j--;
            }
            
            //move up
            else if(dp[i-1][j]>dp[i][j-1]){ 
                ans+=s1[i-1];
                i--;
            }
            
            //move down
            else{
                ans+=s2[j-1];
                j--;
            }
        }
        
        // if str2 reaches its end,  put remaining characters of
        // str1 in ind
        while(i>0){
            ans+=s1[i-1];i--;
        }
        
        // if str1 reaches its end,  put remaining characters of
        // str2 in ind
        while(j>0){
            ans+=s2[j-1];j--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //     int ans=0;
    // int f(int ind1,int ind2,string& s1, string& s2, vector<vector<int>>&dp){
        
    //     if(ind1<0||ind2<0)return 0;
        
    //     if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
    //     //match case
        
    //     int len=0;
    //     if(s1[ind1]==s2[ind2]){
    //         len= 1+f(ind1-1,ind2-1,s1,s2,dp);
    //     }
        
    //     //not match
    //   f(ind1-1,ind2,s1,s2,dp);
    //   f(ind1,ind2-1,s1,s2,dp);
        
    //     ans=max(ans,len);
    //     return dp[ind1][ind2]=len;
        
    // }
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // f(n-1,m-1,s1,s2,dp);
        // return ans;
        
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans=INT_MIN;
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
                    ans=max(ans,dp[ind1][ind2]);
                }
                else{
                    dp[ind1][ind2]=0;
                }
            }
        }
        if(ans==INT_MIN)return 0;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
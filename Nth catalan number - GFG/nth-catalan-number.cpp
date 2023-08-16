//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int MOD=1e9+7;
    long long solve(int n,vector<int>&dp){
        
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];
        // catalan(n) is sum of
        // catalan(i)*catalan(n-i-1)
         long long  res = 0;
        for (int i = 0; i < n; i++)
        {  res += (solve(i,dp) * solve(n - i - 1,dp))%MOD;
          res=res%MOD;
        }
         return dp[n]=res%MOD;
        
    }
    int findCatalan(int n) 
    {
        //code here
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends
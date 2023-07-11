//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int m, int n)
    {
       
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        for(int i=0;i<=m;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=n;j++){
            dp[0][j]=0;
        }
    
        for(int ind1=1;ind1<=m;ind1++){  
            for(int ind2=1;ind2<=n;ind2++){   
                
                if(s1[ind1-1]==s2[ind2-1]){
                    dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
    
        int si= dp[m][n];
        
        int len=n+m-si;//shortest Common Supersequence length
        return len;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends
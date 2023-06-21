//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int f(int ind,int price[], int len, vector<vector<int>>&dp){
      if(len==0)return 0;
      if(ind==0){
         
         return len*price[0]; 
      }
      
      if(dp[ind][len]!=-1)return dp[ind][len];
      
      int notTake=0+f(ind-1,price,len,dp);
      int take=INT_MIN;
      if(len>=ind+1){
          take=price[ind]+f(ind,price,len-(ind+1),dp);
      }
      
      return dp[ind][len]=  max(take,notTake);
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
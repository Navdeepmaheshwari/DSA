//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int solve(int ind,int prev,vector<vector<int>>& points,int n,vector<vector<int>>&dp){
      if(ind==0){
        int ans=0;
        for(int i=0;i<3;i++){
          if(prev!=i)
            ans= max(ans,points[ind][i]);
        }
        return ans;
      }
  
      
      if(dp[ind][prev]!=-1)return dp[ind][prev];
      
      int ans=0;
      for(int i=0;i<3;i++){
          if(prev!=i)
            ans=max(ans,points[ind][i]+solve(ind-1,i,points,n,dp));
      }
      return dp[ind][prev]=ans;
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return solve(n-1,3,points,n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
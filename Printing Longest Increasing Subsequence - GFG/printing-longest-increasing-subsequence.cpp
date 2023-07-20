//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        int maxi=1;
        int last=0;
        vector<int>dp(n,1),hash(n,0);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                
                if(arr[j]<arr[i]&&1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
          
         //for last index
          if(dp[i]>maxi){
             maxi=dp[i];
             last=i;
          }
        }
        
        vector<int>lis;
        lis.push_back(arr[last]);
        while(hash[last]!=last){
            last=hash[last];
            lis.push_back(arr[last]);
        }
        
        reverse(lis.begin(),lis.end());
        return lis;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
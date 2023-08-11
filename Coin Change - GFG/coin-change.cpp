//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int amount) {

        // code here.
          vector<vector< long long int>>dp(n,vector< long long int>(amount+1,0));
        
        for(int target=0;target<=amount;target++){
            dp[0][target]=(target%coins[0]==0);
        }
        
        for(int ind=1;ind<n;ind++){
            
            for(int target=0;target<=amount;target++){
                
                 long long int notTake=dp[ind-1][target];
                 long long int take=0;

                if(coins[ind]<=target){
                    take=dp[ind][target-coins[ind]];
                }
                
                dp[ind][target]=notTake+take;
                
            }
        }
        return dp[n-1][amount];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
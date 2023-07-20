//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        int maxi=1;
        int last=0;
        sort(arr.begin(),arr.end());//sorting helps to convert problem into LIS
        vector<int>dp(n,1),hash(n,0);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                
                if(arr[i]%arr[j]==0&&1+dp[j]>dp[i]){
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
        
        vector<int>lds;
        lds.push_back(arr[last]);
        while(hash[last]!=last){
            last=hash[last];
            lds.push_back(arr[last]);
        }
        
        reverse(lds.begin(),lds.end());
        return lds;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends
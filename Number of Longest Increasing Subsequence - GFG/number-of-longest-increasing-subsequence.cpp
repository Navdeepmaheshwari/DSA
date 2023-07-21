//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int lis=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(arr[i]>arr[j]&&1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    cnt[i]=cnt[j];
                }
                else if(arr[i]>arr[j]&&1+dp[j]==dp[i]){
                    //increase the count
                    cnt[i]+=cnt[j];
                }
                
            }
            lis=max(lis,dp[i]);
        }
        
        for(int i=0;i<n;i++){
            
            if(dp[i]==lis){
                ans+=cnt[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
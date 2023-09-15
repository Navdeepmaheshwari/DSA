//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool subsum(int ind,int arr[],int sum,int n, vector<vector<int>>&dp){
        
        if(sum==0)return true;
        if(ind==0)return (arr[0]==sum);
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        
        bool notTake=subsum(ind-1,arr,sum,n,dp);
        bool take=false;
        
        if(sum>=arr[ind]){
            take=subsum(ind-1,arr,sum-arr[ind],n,dp);
        }
        
        return dp[ind][sum]=notTake||take;
    }
    
    bool isSubsetSum(int arr[],int n, int sum){
        // code here 
        
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
       return subsum(n-1,arr,sum,n,dp);
    
    // dp[]
    }
    
    int equalPartition(int n, int arr[])
    {
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=arr[i];
        }
        if(totalSum%2!=0)return false;
    int target=totalSum/2;
    return isSubsetSum(arr,n,target);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
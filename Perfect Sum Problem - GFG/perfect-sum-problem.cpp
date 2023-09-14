//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=(int)1e9+7;
	int f(int ind,int arr[],int sum,vector<vector<int>>&dp ){
// 	  if(sum==0)return 1;  
	 if(ind==0){
	   //  return (sum==arr[ind]);
	   if(sum==0&&arr[0]==0)return 2;
	   if(sum==0||sum==arr[ind])return 1;
	   return 0;
	 }
	    
	    if(dp[ind][sum]!=-1)return dp[ind][sum];
	    int notTake=f(ind-1,arr,sum,dp);
	    int take=0;
	    if(sum>=arr[ind]){
	        take=f(ind-1,arr,sum-arr[ind],dp);
	    }
	    
	    return dp[ind][sum]=(take+notTake)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,arr,sum,dp);
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int i,int arr[],int n, vector<int>&dp){
        if(i==0){
            return arr[i];
        }
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick= arr[i]+solve(i-2,arr,n,dp);
        int notPick=0+solve(i-1,arr,n,dp);
        
        return dp[i]=max(pick,notPick);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // vector<int>dp(n,-1);
        // return solve(n-1,arr,n,dp);
        
         vector<int>dp(n,0);
         dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
         for(int i=2;i<n;i++){
             
            int pick=arr[i]+dp[i-2];
            int notPick=0+dp[i-1];
            
            dp[i]=max(pick,notPick);
             
         }
         return dp[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
		if(i>j) return 0;
		if(dp[i][j]!=-1) return dp[i][j];
		int maxi=INT_MIN;
		for(int k=i;k<=j;k++){
			int cost=nums[i-1]*nums[k]*nums[j+1]+
                solve(i,k-1,nums,dp)+
                solve(k+1,j,nums,dp);
			maxi=max(maxi,cost);
		}
		return dp[i][j]=maxi;
	}
        int maxCoins(int n, vector <int> &nums)
        {
            nums.insert(nums.begin(),1);
	     	nums.insert(nums.end(),1);
		    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
		    
		   return solve(1,n,nums,dp);
                // write your code here
        }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
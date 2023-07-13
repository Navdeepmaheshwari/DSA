//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&p){
    //Write your code here..
    int n=p.size();
    int maxTransactions=2;
    
     
        //Tabulation
   vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(maxTransactions+1,0)));
        
        //Base case 
        //as base case in recursion return 0 and in tabulation we initialize dp with 0 
        //so need to write;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=1;cnt<=maxTransactions;cnt++){//for cnt=0 always 0,so start from cnt=1
                    
                int profit = 0;
                if( buy )//means we can buy, here two cases exist whether we want to buy or not
                    profit = max( -p[ind]+ dp[ind+1][0][cnt], dp[ind+1][1][cnt] );
                else
                    profit = max( p[ind]+dp[ind+1][1][cnt-1] , dp[ind+1][0][cnt]);
                
                dp[ind][buy][cnt] = profit; 
                    
                }
            }
        }
        return dp[0][1][maxTransactions];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends
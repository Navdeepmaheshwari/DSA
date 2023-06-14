//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int solve(int idx,int target,vector<int>& nums){
        if(idx==nums.size()){
            if(target==0){
               return 1;
            }
            return 0;
        }
       
       int pos=solve(idx+1,target-nums[idx],nums);
       int neg= solve(idx+1,target+nums[idx],nums);
       return pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,target,nums);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int>dp;
        int ans=1;
        
        for(auto x:arr){
            int cnt=0;
// check if there exists an element (arr[i]-difference) in the map dp such that the difference between the current element and that element is equal to the given difference.
            if(dp.find(x-diff)!=dp.end()){
                cnt=dp[x-diff];
            }
            
            dp[x]=cnt+1;
            ans=max(ans,dp[x]);
        }
        return ans;
    }
};
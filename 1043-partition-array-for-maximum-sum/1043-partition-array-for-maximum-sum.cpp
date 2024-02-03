class Solution {
public:
    
    int dfs(vector<int>&arr, int k, int start, vector<int>& dp){
        int n = arr.size();
        if(start>=n)
            return 0;
        if(dp[start]!=-1) return dp[start];
        int maxsum = arr[start];
        int maxno = arr[start];
        for(int end = start;end<start+k && end<n;end++)
        {
            maxno = max(maxno,arr[end]);
            maxsum = max(maxsum,(maxno*(end-start+1)+dfs(arr,k,end+1,dp)));
        }
        return dp[start] = maxsum;
    }
    
   int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(), -1);
        return dfs(arr, k, 0, dp);
    }
    
   
};
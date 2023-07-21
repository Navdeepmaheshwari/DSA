class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
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
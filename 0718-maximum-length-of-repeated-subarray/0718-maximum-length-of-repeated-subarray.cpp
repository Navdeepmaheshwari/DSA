class Solution {
public:
    int ans=0;
    int f(int ind1,int ind2,vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&dp){
        
        if(ind1<0||ind2<0)return 0;
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        //match case
        
        int len=0;
        if(nums1[ind1]==nums2[ind2]){
            len= 1+f(ind1-1,ind2-1,nums1,nums2,dp);
        }
        
        //not match
       f(ind1-1,ind2,nums1,nums2,dp);
       f(ind1,ind2-1,nums1,nums2,dp);
        
        ans=max(ans,len);
        return dp[ind1][ind2]=len;
        
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        f(n-1,m-1,nums1,nums2,dp);
        return ans;
    }
};
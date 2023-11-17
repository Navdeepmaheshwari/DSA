class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int j=n-1;
        for(int i=0;i<n/2;i++){
            
            int curr=nums[i]+nums[j];
            ans=max(ans,curr);
            j--;
        }
        return ans;
    }
};
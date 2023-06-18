class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            int diff=abs(nums[i]-nums[i-1]);
            ans=min(ans,diff);
            
        }
        return ans;
    }
};
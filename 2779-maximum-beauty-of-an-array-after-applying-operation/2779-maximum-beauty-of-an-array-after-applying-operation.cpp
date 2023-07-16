class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,ans=0;
        for(int j=0;j<n;j++){
            
            if(nums[j]-nums[i]>2*k)i++;
            else ans=max(ans,j-i+1);
        }
        return ans;
        
    }
};
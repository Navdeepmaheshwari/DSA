class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        
        long long ans=0;
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int med=n/2;
        
        if(nums[med]<k){
            int i=med;
            while(i<n&&nums[i]<k){ 
                ans+=k-nums[i];
                i++;
            };
        }
        else if(nums[med]>k){
            int i=med;
            while(i>=0&&nums[i]>k){
                ans+=nums[i]-k;
                i--;
            } 
        }
        
        return ans;
        
        
    }
};
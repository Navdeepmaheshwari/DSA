class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int th) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){

            if(nums[i]<=th&&nums[i]%2==0){
                int j=i+1;
                while(j<n && nums[j]<=th  && nums[j]%2!=nums[j-1]%2){
                    j++;
                } 
                ans=max(ans,j-i);
            }
          
        }
        return ans;
    }
};
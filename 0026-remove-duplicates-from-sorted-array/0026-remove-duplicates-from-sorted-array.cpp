class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[j]=nums[i];
                
                j++; 
            }
        }
        for(auto x:nums){
            cout<<x<<" ";
        }
        return j;
    }
};
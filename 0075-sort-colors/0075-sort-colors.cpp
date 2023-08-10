class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int last=n-1,first=0;
        for(int i=0;i<=last;i++){
           
            if(nums[i]==2){
                swap(nums[i],nums[last]);
                last--;i--;
            } 
            else if(nums[i]==0){
                swap(nums[i],nums[first]);
                first++;
            }
        
        }
    }
};
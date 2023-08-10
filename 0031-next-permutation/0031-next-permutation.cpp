class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind=-1;

        //first find out the breaking point 
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }

        // if there is no breaking  point 
        if(ind==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            // find next greater element and swap with ind
            for(int i=n-1;i>=ind;i--){

                if(nums[i]>nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }

            // reverse the rest right half ind+1 to n
            reverse(nums.begin()+ind+1,nums.end());
        }
    }
};
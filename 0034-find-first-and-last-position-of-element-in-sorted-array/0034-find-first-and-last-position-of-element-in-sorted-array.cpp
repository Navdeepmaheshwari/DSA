class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1;
        int i=-1,j=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(nums[mid]==target){
               int temp=mid;
                while(mid>0&&nums[mid-1]==target){
                    mid--;
                }
                i=mid;
                
                while(temp<n-1&&nums[temp+1]==target){
                    temp++;
                }
                j=temp;
                return {i,j};
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
               h=mid-1; 
            }
        }
        return {i,j};
    }
};
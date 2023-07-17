class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(nums[mid]==target){
                int temp=mid;
                while(mid>0&&nums[mid-1]==target){
                    ans.push_back(mid-1);
                    mid--;
                }
                reverse(ans.begin(),ans.end());
                ans.push_back(temp);
                while(temp<n-1&&nums[temp+1]==target){
                    ans.push_back(temp+1);
                    temp++;
                }
                return ans;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};
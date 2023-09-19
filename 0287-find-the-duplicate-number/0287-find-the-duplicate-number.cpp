class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int, int>numb;
        
        for(int i=0;i<n;i++){
            numb[nums[i]]++;
            
            if(numb[nums[i]]>1){
                return nums[i];
            }
        }
        return 0;
    }
    
};
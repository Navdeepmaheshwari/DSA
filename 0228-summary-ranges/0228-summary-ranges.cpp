class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string>res;
        int n = nums.size();
        
        string arr="->";
        int i=0;
        while(i<n){
            int start,end;
            start=nums[i];
            while(i+1<nums.size() && nums[i]==nums[i+1]-1){ 
                i++;
            }
            end=nums[i];
            if(start==end){
                res.push_back(to_string(start));
            }
            else{
                 res.push_back(to_string(start)+arr+ to_string(end));
            }
           i++;
        }
        return res;
    }
};
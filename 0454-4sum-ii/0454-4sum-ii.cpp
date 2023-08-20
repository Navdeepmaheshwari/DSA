class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        
        unordered_map<int,int> mp;
        for(auto k : nums3){
            for(auto l : nums4){
                mp[k + l]++;
            }
        }
        
        int cnt=0;
        for(auto i:nums1){
            for(auto j:nums2){
               
                if(mp.find(-(i+j))!=mp.end()){
                    cnt+=mp[-(i+j)];
                }
            }
        }
        return cnt;
    }
};
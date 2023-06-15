class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int n=nums.size();
        int maxx=*max_element(nums.begin(),nums.end());
        for(int i=1;i<=max(maxx,1);i++){
            if(mp.find(i)==mp.end())return i;
        }
        return maxx+1;
    }
};
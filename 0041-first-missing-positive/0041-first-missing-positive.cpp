class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(auto x:nums){
        //     mp[x]++;
        // }
        // int n=nums.size();
        // int maxx=*max_element(nums.begin(),nums.end());
        // for(int i=1;i<=max(maxx,1);i++){
        //     if(mp.find(i)==mp.end())return i;
        // }
        // return maxx+1;
        
        int n=nums.size();
        for(int i=0 ; i<n ; i++)
        {
            while(nums[i]>0 and nums[i]<=n and nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0 ; i<n ; i++) if(nums[i] != i+1) return i+1;
        return n+1;
    }
};
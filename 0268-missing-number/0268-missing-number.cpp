class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        
        int xor_nums=0;
        int xor_indx=0;
        
        for(int i=0;i<n;i++){
            xor_nums=xor_nums^nums[i];
            xor_indx=xor_indx^i;
        }
        
        xor_indx=xor_indx^n; //we have to take [0,n] that's why
        
        return xor_nums^xor_indx;
        
//         unordered_map<int,int>mp;
//         for(auto x:nums){
//             mp[x]++;
//         }
        
//         for(int i=0;i<=n;i++){
//             if(mp.find(i)==mp.end())return i;
//         }
//         return -1;
    }
};
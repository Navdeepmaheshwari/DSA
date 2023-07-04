class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
//         unordered_map<int,int>mp;
//         for(auto x:nums){
//             mp[x]++;
//         }
        
//         for(auto i:mp){
            
//             if(i.second==1)return i.first;
//         }
//         return -1;
        
        int res=0;
        for(int i=0;i<32;i++){
            
            int cnt=0;
            for(auto num:nums){
                cnt+=((num>>i)&1);
            }
            // cout<<cnt<<endl;
            cnt=cnt%3;
            res=res|(cnt<<i);
        }
        return res;

    }
};
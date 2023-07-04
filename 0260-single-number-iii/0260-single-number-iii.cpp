class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
//         unordered_map<int,int>mp;
//         vector<int>ans;
//         for(auto x:nums){
//             mp[x]++;
//         }
//         for(auto i:mp){
//             if(i.second==1)ans.push_back( i.first);
//         }
//         return ans;
        
        int XOR=0;
        int first=0;
        for(auto x:nums){
            XOR^=x;
        }
        // cout<<XOR<<endl;
        
        // get rightmost set bit in above xor
        int mask=1;
        while(!(XOR&mask)){
            mask=mask<<1;
        }
        
        //using mask finding the first num
        for(auto &x:nums){
            // cout<<x<<" ";
            if(x&mask){
                // cout<<x<<endl;
                first=first^x;
            }
            // cout<<endl;
        }
        
       
        return {first,first^XOR};
    }
    
};
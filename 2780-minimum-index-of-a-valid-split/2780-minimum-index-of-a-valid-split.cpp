class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;  
        }
        int dominant=-1,cnt=0;//dominant element & its count
        for(auto&x:mp){
            if(x.second*2>n){
                dominant=x.first;
                cnt=x.second;
                break;
            }
        }
        // cout<<dominant<<" "<<cnt;
        int leftcnt=0,rightcnt=0;
        for(int i=0;i<n-1;i++){
            
            if(nums[i]==dominant)leftcnt++;
            rightcnt=cnt-leftcnt;
            
            //check that index i can be splitIndex or not
            //dominant condition chk
            if(leftcnt*2>i+1 &&rightcnt*2>n-i-1){
                return i;
            }
        }
        return -1;
        
    }
};
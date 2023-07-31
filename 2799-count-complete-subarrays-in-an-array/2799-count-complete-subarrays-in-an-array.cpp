class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ans=0;
        unordered_set<int>st;
        for(auto x:nums){
            
            st.insert(x);
        }
        cnt=st.size();
        
        if(cnt==1)return n*(n+1 )/2;
        
        for(int i=0;i<n;i++){
            unordered_set<int>temp;
            for(int j=i;j<n;j++){
                
                temp.insert(nums[j]);
                if(temp.size()==cnt){
                    ans++;
                }
            }
        }
        return ans;
        
        
    }
};
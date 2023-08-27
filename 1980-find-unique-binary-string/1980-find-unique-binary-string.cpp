class Solution {
public:
    void solve(int ind,int n,unordered_set<string>&st,string curr, vector<string>&ans){
        
        if(ind==n){
            if(st.find(curr)==st.end())
                ans.push_back(curr);
              // cout<<curr<<endl;
            return;
        }
        
        solve(ind+1,n,st,curr+"0",ans);
        solve(ind+1,n,st,curr+"1",ans);
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string>st;
        
        for(auto x:nums){
            st.insert(x);
        }
        vector<string>ans;
        solve(0,n,st,"",ans);
        return ans[0];
        
    }
};
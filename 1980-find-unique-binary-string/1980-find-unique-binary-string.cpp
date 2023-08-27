class Solution {
public:
    void solve(int ind,int n,unordered_set<string>&st,string curr,string&ans){
        if(ans!="")return;
        if(ind==n){
            if(st.find(curr)==st.end())
                ans=curr;
              // cout<<curr<<endl;
            return;
        }

        solve(ind+1,n,st,curr+"0",ans);
        solve(ind+1,n,st,curr+"1",ans);
        
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string>st(nums.begin(),nums.end());
        string ans="";
        solve(0,n,st,"",ans);
        return ans;
    }
};
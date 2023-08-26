class Solution {
public:
    static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),compare);
         for(auto pair:pairs){
            cout<<"[ ";
            for(auto x:pair){
                cout<<x<<" ";
            }
            cout<<"]"<<endl;
        }
        int ans=1;
        vector<int>prev=pairs[0];
        for(int i=1;i<n;i++){
            auto curr=pairs[i];
            if(prev[1]<curr[0]){
                ans++;
                prev=curr;
            }
        }
        return ans;
    }
};
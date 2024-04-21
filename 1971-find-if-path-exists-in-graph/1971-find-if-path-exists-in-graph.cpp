class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(auto i:edges){
           mp[i[0]].push_back(i[1]);
           mp[i[1]].push_back(i[0]);
        }
        vector<int>visited(n,0);
        stack<int>st;
        st.push(source);

        while(!st.empty()){

            auto top=st.top();
            if(top==destination){
                return true;
            }
            st.pop();
            for(auto x:mp[top]){
                if(!visited[x]){
                    visited[x]=1;
                    st.push(x);
                }
            }
        }
        return false;
    }
};
class Solution {
public:
void dfs(unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& adj, vector<string>& ans, string s) {
    
        while (!adj[s].empty()) {
            string next = adj[s].top();
            adj[s].pop();
            dfs(adj, ans, next);
        }
        
        ans.push_back(s);
    }
vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        vector<string> ans;

        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        
        dfs(adj, ans, "JFK");

        reverse(ans.begin(), ans.end());
        
        return ans;
    }
    

};
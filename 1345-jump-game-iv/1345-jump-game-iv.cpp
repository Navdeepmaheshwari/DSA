class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        vector<int> vis(n);
        vis[0] = true;
        queue<int> q;
        q.push(0);
        int cnt = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1) return cnt;
                vis[curr]=true;
                if (curr + 1 < n && !vis[curr + 1]) {
                    q.push(curr + 1);
                }
                if (curr - 1 >= 0 && !vis[curr - 1]) {
                    q.push(curr - 1);
                }
                for (int x : mp[arr[curr]]) {
                    if (x != curr && !vis[x]) {
                        q.push(x);
                    }
                }
                mp[arr[curr]].clear();
            }
            cnt++;
        }
        return -1;
    }
};
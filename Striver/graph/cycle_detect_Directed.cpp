// using DFS
#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto x : adj[node])
    {
        if (!vis[x])
        {
            if (dfs(x, adj, vis, pathVis) == true)
                return true;
        }
        else if (pathVis[x])
        {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for (int i = 0; i < V; i++)
    {

        if (!vis[i])
        {
            if (dfs(i, adj, vis, pathVis) == true)
                return true;
        }
    }
    return false;
}

// using BFS-->Khan's Algorithm

bool isCycle(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            indegree[x]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        { // push node whose indegree is 0;
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;

        for (auto x : adj[node])
        {
            indegree[x]--; // decrease indegree of adjacent nodes by 1
            if (indegree[x] == 0)
            { // if indegree of adjacent node become 0 push it in queue
                q.push(x);
            }
        }
    }
    if (cnt == V)
        return false; // loop exactly runs V times
    return false;
}
int main()
{
    int V = 6;
    vector<int> adj[] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    bool ans = isCyclic(V, adj);
    cout << ans;
    return 0;
}
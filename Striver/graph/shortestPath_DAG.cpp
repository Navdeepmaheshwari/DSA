#include <bits/stdc++.h>
using namespace std;
void topoSort(int node, vector<pair<int, int>> adj[],
              vector<int> &vis, stack<int> &st)
{

    vis[node] = 1;
    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
        {
            topoSort(v, adj, vis, st);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<pair<int, int>> graph[N]; // DAG
    for (auto x : edges)
    {
        int u = x[0];
        int v = x[1];
        int wt = x[2];
        graph[u].push_back({v, wt});
    }

    stack<int> st;
    vector<int> vis(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            topoSort(i, graph, vis, st);
        }
    }

    vector<int> dist(N, 1e9);
    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        for (auto x : graph[node])
        {
            int wt = x.second;
            int adj = x.first;

            if (dist[node] + wt < dist[adj])
            {
                dist[adj] = dist[node] + wt;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}
int main()
{
    int N = 5, M = 5;

    vector<vector<int>> edges = {{0, 1, 2}, {2, 1, 2}, {2, 4, 2}, {1, 4, 8}, {1, 3, 6}};

    vector<int> ans = shortestPath(N, M, edges);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    return 0;
}
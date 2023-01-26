#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{

    vis[node] = 1;
    for (auto x : adj[node])
    {

        if (!vis[x])
        {
            dfs(x, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> topo;
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
int main()
{

    return 0;
}
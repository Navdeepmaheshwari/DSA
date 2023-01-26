#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> &vis, vector<int> &pathVis,
         vector<int> &check, vector<vector<int>> &graph)
{

    vis[node] = 1;
    pathVis[node] = 1;

    for (auto x : graph[node])
    {

        if (!vis[x])
        {
            if (dfs(x, vis, pathVis, check, graph) == true)
            {
                check[node] = 0;
                return true;
            }
        }
        else if (pathVis[x])
        {
            check[node] = 0;
            return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> safe;
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, pathVis, check, graph);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (check[i] == 1)
        {
            safe.push_back(i);
        }
    }
    return safe;
}
int main()
{

    return 0;
}
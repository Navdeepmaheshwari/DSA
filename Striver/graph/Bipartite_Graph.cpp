#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int colr, vector<int> &color, vector<vector<int>> &graph)
{
    color[node] = colr;
    for (auto x : graph[node])
    {

        if (color[x] == -1)
        {
            if (dfs(x, !colr, color, graph) == false)
                return false;
        }
        else if (color[x] == color[node])
        {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {

        if (color[i] == -1)
        {
            if (dfs(i, 0, color, graph) == false)
                return false;
        }
    }
    return true;
}
int main()
{

    return 0;
}
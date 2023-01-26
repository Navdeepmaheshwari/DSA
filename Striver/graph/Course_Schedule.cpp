#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int V, vector<vector<int>> &pr)
{

    vector<int> adj[V];
    for (int i = 0; i < pr.size(); i++)
    {
        int u = pr[i][1];
        int v = pr[i][0];
        adj[u].push_back(v);
    }
    vector<int> indegree(V, 0);
    vector<int> topo;
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

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto x : adj[node])
        {
            indegree[x]--; // decrease indegree of adjacent nodes by 1
            if (indegree[x] == 0)
            { // if indegree of adjacent node become 0 push it in queue
                q.push(x);
            }
        }
    }
    if (topo.size() == V)
        return topo;
    return {};
}

int main()
{

    return 0;
}
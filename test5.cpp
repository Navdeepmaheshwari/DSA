#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> MST;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // pair<int, pair<int, int>>
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
        pq;
    vector<int> vis(V, 0);
    pq.push({0, {0, -1}}); // wt,node,parent
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if (vis[node])
            continue;
        vis[node] = 1;
        sum += wt;
        if (parent != -1)
        {
            MST.push_back({parent, node});
        }

        for (auto x : adj[node])
        {
            int adjNode = x[0];
            int edw = x[1];
            if (!vis[adjNode])
            {
                pq.push({edw, {adjNode, node}});
            }
        }
    }

    return sum;
}
int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}};
    vector<vector<int>> adj[V];
    for (auto it : edges)
    {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    int sum = spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << sum << endl;
    cout << "Minimum Spanning Tree Edges are:" << endl;
    for (auto x : MST)
    {

        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
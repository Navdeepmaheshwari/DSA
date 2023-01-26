#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[S] = 0;
    pq.push({0, S}); //{dist,node}
    while (!pq.empty())
    {

        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto x : adj[node])
        {
            int wt = x[1];
            int adjnode = x[0];
            if (wt + dis <= dist[adjnode])
            {
                dist[adjnode] = wt + dis;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }
    return dist;
}
int main()
{

    return 0;
}
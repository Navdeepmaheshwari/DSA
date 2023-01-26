#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    vector<int> adj[N];
    for (auto x : edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    vector<int> dis(N, INT_MAX);
    queue<int> q;
    dis[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto adjNode : adj[node])
        {

            if (dis[adjNode] > dis[node] + 1)
            {
                dis[adjNode] = dis[node] + 1;
                q.push(adjNode);
            }
        }
    }
    vector<int>ans(N,-1);

    for(int i=0;i<N;i++){
        if(dis[i]!=INT_MAX){
            ans[i]=dis[i];
        }
    }
    return ans;
}

int main()
{

    int N = 9, M = 10;
    vector<vector<int>> edges = {{0, 1}, {0, 3}, {3, 4}, {4, 5}, {5, 6}, {1, 2}, {2, 6}, {6, 7}, {7, 8}, {6, 8}};

    vector<int> ans = shortestPath(edges, N, M, 0);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    return 0;
}
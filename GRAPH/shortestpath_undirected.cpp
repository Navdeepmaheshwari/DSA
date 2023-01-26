#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
void ShortestpathArray(vector<int> adj[], int v, int s)
{
    vector<int> dist;

    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        dist.push_back(INT_MAX);
    }
    queue<int> q;
    visited[s] = true;
    dist[s] = 0;
    q.push(s);
    while (q.empty() == false)
    {

        int temp = q.front();
        q.pop();
        // cout << temp << " ";

        for (int v : adj[temp])
        {
            if (visited[v] == false)
            {
                dist[v] = dist[temp] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for (int i : dist)
    {
        cout << i << " ";
    }
    // return dist;
}
int main()
{
    int v = 8; // no of vertices
    vector<int> adj[v];

    addEdge(adj, 1,0);
    addEdge(adj,2,1);
    addEdge(adj, 0,3);
    addEdge(adj, 3,7);
    addEdge(adj, 3,4);
    addEdge(adj, 7,4);
    addEdge(adj,7,6);
    addEdge(adj, 4,5);
    addEdge(adj, 4,6);
    addEdge(adj, 6,5);

    // printGraph(adj, v);

    cout << "Shortest Path Array" << endl;
    ShortestpathArray(adj, v, 0);
    /*  for (int i : dis)
     {
         cout << i << " ";
     }
     cout << endl; */
    return 0;
}
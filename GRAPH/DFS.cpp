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

void DFSRecursive(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            DFSRecursive(adj, u, visited);
        }
    }
}
void DFS(vector<int> adj[], int v, int s)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    DFSRecursive(adj, s, visited);
}
int main()
{
    int v = 7; // no of vertices
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);

    // printGraph(adj, v);

    cout << "DFS of Graph" << endl;
    DFS(adj, v, 0);
    return 0;
}
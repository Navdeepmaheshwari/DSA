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

bool DFSRecursive(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    // cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false)
        {
            if (DFSRecursive(adj, u, visited, s) == true)
            {
                return true;
            };
        }
        else if (u != parent)
        {
            return true;
        }
    }
    return false;
}
bool DFS(vector<int> adj[], int v)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {

            if (DFSRecursive(adj, i, visited, -1) == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{

    /*  //? DisConnected Graph
     int v = 7; // no of vertices
     vector<int> adj[v];
     //* graph-1
     addEdge(adj, 0, 1);
     addEdge(adj, 0, 2);
     addEdge(adj, 1, 3);
     addEdge(adj, 2, 3);

     // graph-2
     addEdge(adj, 4, 5);
     addEdge(adj, 4, 6);
     addEdge(adj, 5, 6); */

    //? Connected Graph
    int v = 6; // no of vertices
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);

    // printGraph(adj, v);

    // cout << "DFS of Graph" << endl;
    bool iscycle = DFS(adj, v);
    if (iscycle)
    {
        cout << "Cycle Present";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
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

bool DFSRecursive(vector<int> adj[], int s, bool visited[], bool recStack[])
{
    visited[s] = true;
    recStack[s] = true;
    // cout << s << " ";
    for (int u : adj[s])
    {
        if (visited[u] == false && DFSRecursive(adj, u, visited, recStack) == true)
        {

            return true;
        }
        else if (recStack[u] == true)
        {
            return true;
        }
    }

    recStack[s] = false;
    return false;
}
bool DFS(vector<int> adj[], int v)
{
    bool visited[v];
    bool recStack[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {

            if (DFSRecursive(adj, i, visited, recStack) == true)
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{

    //? Connected Graph
    int v = 6; // no of vertices
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    // printGraph(adj, v);

    // cout << "DFS of Graph" << endl;
    bool iscycle = DFS(adj, v);
    if (iscycle)
    {
        cout << "Cycle Present";
    }
    else
    {
        cout << "Cycle not Present";
    }
    return 0;
}
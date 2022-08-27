#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
}

void printGraph(vector<pair<int, int>> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (pair<int, int> x : adj[i])
        {
            cout << "{ " << x.first << " , " << x.second << " } ";
            // cout << ",";
        }
        cout << endl;
    }
}

int main()
{

    //? Connected Graph
    int V = 6; // no of vertices
    vector<pair<int, int>> adj[V];

    //? Directed Acyclic Graph
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 6);
    addEdge(adj, 0, 4, 1);
    addEdge(adj, 4, 2, 2);
    addEdge(adj, 4, 5, 4);
    addEdge(adj, 5, 3, 1);

    //? Directed Cyclic Graph
    /* addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 3);
    addEdge(adj, 4, 5); */

    printGraph(adj, V);

    return 0;
}
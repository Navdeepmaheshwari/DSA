#include <bits/stdc++.h>
using namespace std;
#define NIL -1
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
void printvector(vector<int> vec)
{
    for (int i : vec)
    {
        cout << i << " ";
    }
}
void printvector1(vector<bool> vec)
{
    for (bool i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
}

void APrec(vector<int> adj[], int u, int V, vector<bool> &visited, vector<int> &low, vector<int> &discovery_time,
           vector<int> &parent, vector<bool> &ap)
{
    static int time = 0;
    int children = 0;
    visited[u] = true;
    discovery_time[u] = low[u] = ++time;

    /*  for (int i = 0; i < V; i++)
     { */
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APrec(adj, v, V, visited, low, discovery_time, parent, ap);
            low[u] = min(low[u], low[v]);

            //* u is an articulation point in following cases
            //* (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == NIL && children > 1)
                ap[u] = true;

            //* (2) If u is not root and low value of one of its child is more than discovery value of u.
            if (parent[u] != NIL && low[v] >= discovery_time[u])
                ap[u] = true;
        }
        else if (v != parent[u])
            low[u] = min(low[u], discovery_time[v]);
    }
    // }
}
void ArticulationPoint(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    vector<int> low(V, 0);
    vector<int> discovery_time(V, 0);
    vector<int> parent(V, NIL);
    vector<bool> ap(V, false);

    /*   for (int i = 0; i < V; i++)
      {
          parent[i] = NIL;
          visited[i] = false;
          ap[i] = false;
      } */

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            APrec(adj, i, V, visited, low, discovery_time, parent, ap);
        }
    }
    /* cout << "DISCOVERY TIME:";
    printvector(discovery_time);
    cout << "Low : ";
    printvector(low);
    cout << "AP :";*/
    // printvector1(visited);

    for (int i = 0; i < V; i++)
        if (ap[i] == true)
            cout << i << " ";
}
int main()
{
    int V = 5; // no of vertices
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 3);

    printGraph(adj, V);
    ArticulationPoint(adj, V);

    return 0;
}
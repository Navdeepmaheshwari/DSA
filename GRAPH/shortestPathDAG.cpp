
//? Khan's Algorithm (BFS)
#include <bits/stdc++.h>
using namespace std;
int INF = INT_MAX;
void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
}

void printGraph(vector<pair<int, int>> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {cout << i << "->";
        for (pair<int, int> x : adj[i])
        {
            cout << "{ " << x.first << " " << x.second << " }";
        }
        cout << endl;
    }
}
void topo_rec(vector<pair<int, int>> adj[], int V, int u, bool visited[], stack<int> &st)
{
    visited[u] = true;
    // vector<pair<int, int>> x = adj[u];
    // pair<int, int> temp = x[u];
    for (auto v : adj[u])
    {
        if (visited[v.first] == false)
        {
            topo_rec(adj, V, v.first, visited, st);
        }
    }
    st.push(u);
}
vector<int> topologicalSort(vector<pair<int, int>> adj[], int V)
{
    stack<int> st;
    vector<int> topo;
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {

            topo_rec(adj, V, i, visited, st);
            // cout << endl;
        }
    }

    while (st.empty() == false)
    {
        // cout << st.top() << " ";
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}
void shortestPath(vector<pair<int, int>> adj[], int V, int s)
{
    vector<int> dist;
    for (int i = 0; i < V; i++)
    {
        dist.push_back(INF);
    }
    dist[s] = 0;
    vector<int> topo = topologicalSort(adj, V);
    cout << "\nTOPOLOGICAL SORT" << endl;
    for (int i : topo)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int u : topo)
    {
        if (dist[u] != INF)
        {
            for (auto v : adj[u])
            {
                if (dist[v.first] > (dist[u] + v.second))
                {
                    dist[v.first] = (dist[u] + v.second);
                }
            }
        }
    }

    cout << "\nThe distances from the src node are: \n";

    for (int i = 0; i < V; ++i)
    {

        if (dist[i] == INF)
            cout << "INF ";

        else
            cout << dist[i] << " ";
    }
}
int main()
{

    //? Connected Graph
    int V = 4; // no of vertices
    vector<pair<int, int>> adj[V];

    //? Directed Acyclic Graph
    /*  addEdge(adj, 0, 1, 2);
     addEdge(adj, 1, 2, 3);
     addEdge(adj, 2, 3, 6);
     addEdge(adj, 0, 4, 1);
     addEdge(adj, 4, 2, 2);
     addEdge(adj, 4, 5, 4);
     addEdge(adj, 5, 3, 1); */

    addEdge(adj, 0, 1, 1);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 4);
    addEdge(adj, 1, 3, 2);
    cout << "\nAdjacency List \n";
    printGraph(adj, V);
    shortestPath(adj, V, 1);

    return 0;
}
//? Khan's Algorithm (BFS)
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

void topo_rec(vector<int> adj[], int V, int u, bool visited[], stack<int> &st)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == false)
        {
            topo_rec(adj, V, v, visited, st);
        }
    }
    st.push(u);
}
void topologicalSort(vector<int> adj[], int V)
{
    stack<int> st;
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
            cout << endl;
        }
    }

    while (st.empty() == false)
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int main()
{

    //? Connected Graph
    int V = 6; // no of vertices
    vector<int> adj[V];

    //? Directed Acyclic Graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);

    // printGraph(adj, v);
    topologicalSort(adj, V);

    return 0;
}
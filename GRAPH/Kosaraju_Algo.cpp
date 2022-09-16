#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
void dfs(vector<int> adj[], int u, stack<int> &st, vector<int> &visited)
{
    visited[u] = true;

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(adj, v, st, visited);
        }
    }

    st.push(u);
}

void revDFS(vector<int> transpose[], int u, vector<int> &visited)
{
    cout << u << " ";
    visited[u] = true;

    for (int v : transpose[u])
    {
        if (!visited[v])
        {
            revDFS(transpose, v, visited);
        }
    }
}
int main()
{
    int V = 5; // no of vertices
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 1);

    // printGraph(adj, V);
    stack<int> st;
    vector<int> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(adj, i, st, visited);
        }
    }
    vector<int> transpose[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;

        for (int v : adj[i])
        {
            transpose[v].push_back(i);
        }
    }
    int cntSCC = 0;
    while (!st.empty())
    {
        int temp = st.top();
        st.pop();

        if (!visited[temp])
        {
            cntSCC++;
            cout << "SCC-" << cntSCC << " : ";
            revDFS(transpose, temp, visited);
            cout << endl;
        }
    }
    cout << "Total SCC : " << cntSCC << endl;
    return 0;
}
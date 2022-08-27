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

void BFS(vector<int> adj[], int s, bool visited[])
{

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (q.empty() == false)
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";

        for (int v : adj[temp])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void BFSDis(vector<int> adj[], int v)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
        {
            BFS(adj, i, visited);
        }
        
    }
}
int main()
{
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
    addEdge(adj, 5, 6);

    // printGraph(adj, v);

    cout << "BFS of Graph" << endl;
    BFSDis(adj, v);  
    return 0;
}
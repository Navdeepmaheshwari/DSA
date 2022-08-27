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

void BFS(vector<int> adj[], int v, int s)
{
    bool visited[v + 1];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

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
}

int main()
{
    int v = 6; // no of vertices
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 0, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 5);

    printGraph(adj, v);

    cout << "BFS of Graph" << endl;
    BFS(adj, v, 0);
    return 0;
}
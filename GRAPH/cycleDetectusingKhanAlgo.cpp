
//? Cycle Detection using Khan's Algorithm
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

bool cycleDetect(vector<int> adj[], int V)
{
    vector<int> indegree;
    vector<int> top_sort;

    for (int i = 0; i < V; i++)
    {

        indegree.push_back(0);
    }
    for (int i = 0; i < V; i++)
    {
        for (int j : adj[i])
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    /* for (int i : indegree)
    {
        cout << i << " ";
    }
    cout << endl; */

    int cnt = 0;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();

        // cout << u << " ";
        top_sort.push_back(u);
        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
        cnt++;
    }

    if (cnt != V)
    {
        return true;
    }
    return false;
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

    //? Directed Cyclic Graph
    /* addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 5, 3);
    addEdge(adj, 4, 5); */

    // printGraph(adj, v);
    bool ans = cycleDetect(adj, V);
    if (ans)
    {
        cout << "There exists a cycle in the graph";
    }
    else
    {
        cout << "There exists no cycle in the graph";
    }

    return 0;
}
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
    int E = 7;
    vector<pair<int, int>> adj[V];

    //? Directed Acyclic Graph
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 1, 2, -2);
    addEdge(adj, 1, 5, -3);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 3, 2, 6);
    addEdge(adj, 3, 4, -2);
    addEdge(adj, 5, 3, 1);
    // printGraph(adj, V);

    int src = 0;
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    //* Relaxing all Edges V-1 times.
     for (int i = 0; i < V - 1; i++)
    {
        for(int j=0;j<V;j++){
        for (auto v : adj[j])
         {
            if (dist[j] != INT_MAX && dist[v.first] > (dist[j] + v.second))
            {
                dist[v.first] = (dist[j] + v.second);
            }
         }
        }
    } 

     bool flag = false;
     for (int i = 0; i < V ; i++)
     {
            for(auto v:adj[i]){
             if (dist[v.first] > (dist[i] + v.second))
             {
                 cout << "negavtive Cycle Detected\n";
                 flag = true;
                 break;
             }
         }
     }

      if (!flag)
     {
   
    for (int i : dist)
    {
        cout << i << " ";
    }
    cout << endl;
    // }

    return 0;
}
}
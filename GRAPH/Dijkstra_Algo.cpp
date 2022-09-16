#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<int> graph[], int V, int s)
{
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;
    vector<bool> finalize(V, false);

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!finalize[i] && (u == -1 || dist[i] < dist[u]))
            {
                u = i;
            }
        }
        finalize[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && finalize[v] == false)
            {
                dist[v] = min(dist[v], (dist[u] + graph[u][v]));
            }
        }
    }

    return dist;
}

int main()
{
    int V = 9;
    vector<int> graph[V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                            {4, 0, 8, 0, 0, 0, 0, 11, 0},
                            {0, 8, 0, 7, 0, 4, 0, 0, 2},
                            {0, 0, 7, 0, 9, 14, 0, 0, 0},
                            {0, 0, 0, 9, 0, 10, 0, 0, 0},
                            {0, 0, 4, 14, 10, 0, 2, 0, 0},
                            {0, 0, 0, 0, 0, 2, 0, 1, 6},
                            {8, 11, 0, 0, 0, 0, 1, 0, 7},
                            {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    /*  int V = 5;
     vector<int> graph[V] = {{0, 2, 0, 6, 0},
                             {2, 0, 3, 8, 5},
                             {0, 3, 0, 0, 7},
                             {6, 8, 0, 0, 9},
                             {0, 5, 7, 9, 0}};
  */
    vector<int> res;
    res = dijkstra(graph, V, 0);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
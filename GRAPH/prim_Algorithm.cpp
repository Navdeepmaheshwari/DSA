#include <bits/stdc++.h>
using namespace std;

int primMST(vector<int> graph[], int V)
{
    int key[V], res = 0;
    fill(key, key + V, INT_MAX);
    key[0] = 0;
    bool mSet[V] = {false};

    for (int count = 0; count < V; count++)
    {
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!mSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }
        mSet[u] = true;
        res = res + key[u];
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && !mSet[v])
            {
                key[v] = min(key[v], graph[u][v]);
            }
        }
    }
    return res;
}

int main()
{
    int V = 5;
    vector<int> graph[V] = {{0, 2, 0, 6, 0},
                            {2, 0, 3, 8, 5},
                            {0, 3, 0, 0, 7},
                            {6, 8, 0, 0, 9},
                            {0, 5, 7, 9, 0}};

   
    int ans = primMST(graph, V);
    cout << ans << endl;

    return 0;
}
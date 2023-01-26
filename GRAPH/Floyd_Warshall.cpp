#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (matrix[i][j] == -1)
            {
                matrix[i][j] = INF;
            }

            if (i == j)
                matrix[i][j] = 0;
        }
    }
    //* Main logic for Floyd Warshall
    /*
    !    Expected Time Complexity: O(n3)
    !    Expected Space Complexity: O(1)
    */
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (matrix[i][j] == INF)
            {
                matrix[i][j] = -1;
            }
        }
    }
}
int main()
{
    int V = 4;
    // graph[i][j]=-1, it means there is no edge from i to j.
    vector<vector<int>> graph = {{0, 5, -1, 10},
                                 {-1, 0, 3, -1},
                                 {-1, -1, 0, 1},
                                 {-1, -1, -1, 0}};
    shortest_distance(graph);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == -1)
                cout << "INF"
                     << "     ";
            else
                cout << graph[i][j] << "     ";
        }
        cout << endl;
    }
    return 0;
}
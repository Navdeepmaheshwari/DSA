/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int ro, int co, vector<vector<int>> &vis, vector<vector<int>> &grid,
         vector<pair<int, int>> &v, int basero, int baseco, int n, int m)
{
    vis[ro][co] = 1;
    v.push_back({ro - basero, co - baseco});

    int delro[] = {-1, 0, 1, 0};
    int delco[] = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        int nro = ro + delro[i];
        int nco = co + delco[i];

        if (nro >= 0 && nro < n && nco >= 0 && nco < m && !vis[nro][nco] && grid[nro][nco] == 1)
        {

            dfs(nro, nco, vis, grid, v, basero, baseco, n, m);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    int cnt = 0;
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int, int>>> st;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                vis[i][j] = 1;
                vector<pair<int, int>> v;
                dfs(i, j, vis, grid, v, i, j, n, m);
                st.insert(v);
            }
        }
    }
    return st.size();
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
                                {1, 0, 0, 0, 0},
                                {0, 0, 0, 0, 1},
                                {1, 1, 0, 1, 1}};
    int ans = countDistinctIslands(grid);
    cout << ans << endl;
    return 0;
}
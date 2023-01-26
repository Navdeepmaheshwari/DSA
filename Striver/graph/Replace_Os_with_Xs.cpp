/*
Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
Replace all ‘O’ with ‘X’ that are surrounded by ‘X’.
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it
*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int ro, int co, vector<vector<char>> mat,
         vector<vector<int>> &vis, int delro[], int delco[], int n, int m)
{
    vis[ro][co] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nro = ro + delro[i];
        int nco = co + delco[i];

        if (nro >= 0 && nro < n && nco >= 0 && nco < m && !vis[nro][nco] && mat[nro][nco] == 'O')
        {
            dfs(nro, nco, mat, vis, delro, delco, n, m);
        }
    }
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delro[] = {-1, 0, 1, 0};
    int delco[] = {0, -1, 0, 1};
    for (int j = 0; j < m; j++)
    {

        if (!vis[0][j] && mat[0][j] == 'O')
        {
            dfs(0, j, mat, vis, delro, delco, n, m);
        }

        if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
        {
            dfs(n - 1, j, mat, vis, delro, delco, n, m);
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (!vis[i][0] && mat[i][0] == 'O')
        {
            dfs(i, 0, mat, vis, delro, delco, n, m);
        }

        if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
        {
            dfs(i, m - 1, mat, vis, delro, delco, n, m);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (vis[i][j] == 0 && mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
        }
    }
    return mat;
}
int main()
{
    vector<vector<char>> grid = {{'X', 'X', 'X', 'X'},
                                 {'X', 'O', 'X', 'X'},
                                 {'X', 'O', 'O', 'X'},
                                 {'X', 'O', 'X', 'X'},
                                 {'X', 'X', 'O', 'O'}};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<char>> ans = fill(n, m, grid);
    for (auto x : ans)
    {

        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
   
}
/*
 Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
 The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code herei
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    int delro[] = {-1, 0, 1, 0};
    int delco[] = {0, -1, 0, 1};
    while (!q.empty())
    {

        int ro = q.front().first.first;
        int co = q.front().first.second;
        int step = q.front().second;
        q.pop();

        ans[ro][co] = step;

        for (int i = 0; i < 4; i++)
        {

            int nro = ro + delro[i];
            int nco = co + delco[i];

            if (nro >= 0 && nro < n && nco >= 0 && nco < m && !vis[nro][nco])
            {

                q.push({{nro, nco}, step + 1});
                vis[nro][nco] = 1;
            }
        }
    }

    return ans;
}
int main()
{
    vector<vector<int>> grid = {{0, 1, 1, 0},
                                {1, 1, 0, 0},
                                {0, 0, 1, 1}};
     vector<vector<int>> ans=nearest(grid);
     for(auto x:ans){

        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
     }
    return 0;
}
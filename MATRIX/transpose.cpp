#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixTranspose(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> transpose;

    for (int j = 0; j < col; j++)
    {
        vector<int> temp;

        for (int i = 0; i < row; i++)
        {

            temp.push_back(grid[i][j]);
        }
        transpose.push_back(temp);
    }
    return transpose;
}

void printMatrix(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> grid = {{3, 2, 1},
                                {1, 7, 6},
                                {2, 7, 7}};

    vector<vector<int>> trans = matrixTranspose(grid);
    cout << "Matrix" << endl;
    printMatrix(grid);
    cout << "\nTranspose of Matrix" << endl;
    printMatrix(trans);
}
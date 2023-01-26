/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

*/
#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<char>> &board, int row, int col, char c)
{
    for (int i = 0; i < 9; i++)
    {
        //* Checking in whole row
        if (board[i][col] == 'c')
            return false;

        //* Checking in whole coloum
        if (board[row][i] == 'c')
            return false;

        //* Checking in 3X3 box
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}
bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {

        for (int j = 0; j < board[0].size(); j++)
        {

            if (board[i][j] == '.')
            {

                for (char c = '1'; c <= '9'; c++)
                {

                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;

                        if (solveSudoku(board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solve(vector<vector<char>> &board)
{
    solveSudoku(board);
}
int main()
{
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    solve(board);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
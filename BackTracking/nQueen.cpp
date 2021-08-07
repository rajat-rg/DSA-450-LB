#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int n, int i, int j)
{
    bool status = true;
    int row = i - 1;
    int col = j;
    while (row >= 0)
    {
        if (board[row][col] != 0)
            return false;
        row--;
    }
    row = i - 1;
    col = j - 1;
    while (col >= 0 and row >= 0)
    {
        if (board[row][col] != 0)
            return false;
        row--;
        col--;
    }
    row = i - 1;
    col = j + 1;
    while (col < n and row >= 0)
    {
        if (board[row][col] != 0)
            return false;
        row--;
        col++;
    }
    return true;
}

bool nQueen(vector<vector<int>> &board, int n, int row)
{
    if (row == n)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, n, row, i))
        {

            board[row][i] = 1;

        if (nQueen(board, n, row + 1))
            return true;

        board[row][i] = 0;
        /* code */
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    nQueen(board, n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
            /* code */
        }
        cout<<endl;
        /* code */
    }
    
    return 0;
}

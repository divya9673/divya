#include <iostream>
using namespace std;

int board[10][10];
int n;

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    int i = row;
    int j = col;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;

        i--;
        j--;
    }

    i = row;
    j = col;

    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return false;

        i--;
        j++;
    }

    return true;
}

bool solveNQueen(int row)
{
    if (row == n)
        return true;

    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            if (solveNQueen(row + 1))
                return true;

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Enter number of queens: ";
    cin >> n;

    if (solveNQueen(0))
    {
        cout << "\nSolution:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No solution found";
    }

    return 0;
}
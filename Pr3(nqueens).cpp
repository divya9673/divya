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
/*
N-Queens Using Backtracking
Step 1: Start
Step 2: Read the number of queens N
Step 3: Initialize an N×N chessboard with all
positions set to 0
Step 4: Place queens column by column
Step 5: For each column:
● Try placing a queen in all rows
● Check if the position is safe:
○ No queen in the same row
○ No queen in the upper diagonal
○ No queen in the lower diagonal
Step 6:
● If safe, place the queen and move to next column
● If not safe, try the next row
Step 7:
● If no row is valid, remove the previously placed
queen (backtrack)
Step 8: Repeat until all queens are placed
Step 9: Display the solution
Step 10: Stop
*/

/*
Enter number of queens: 4

Solution:
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 
*/
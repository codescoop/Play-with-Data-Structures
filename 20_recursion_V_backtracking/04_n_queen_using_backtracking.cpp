/*
    Topic - N-Queen Using Backtracking

    We have (N x N) chess board. We have to place N-Queens such that all queens are safe & no queens
    cuts each other.

    - print the cess board after placing N-Queens on it.
    - print all possible ways in which N-Queens can be placed on chess board.
    - count the number of ways in which N-Queens can be placed on chess board.

*/

#include <iostream>
using namespace std;

int count = 0;             // global variable


// function to check for safe cell when placing queens on board
bool isSafe(char board[][20], int row, int col, int n)
{
    //check for column
    for(int i=0; i<row; i++)
    {
        if(board[i][col] == 1)
        {
            return false;
        }
    }
    // check for left diagonal
    int x = row;
    int y = col;
    while(x>=0 && y>=0)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    // check for  right diagonal
    x = row;
    y = col;
    while(x>=0 && y<n)
    {
        if(board[x][y] == 1)
        {
            return false;
        }
        x--;
        y++;
    }
    // The position is now safe, after checking with the columns & both diagnols
    return true;
}


// function to place N-queens on NxN board
bool solveNQueens(char board[][20], int row, int n)
{
    // Base Case
    if(row == n)
    {
        // you have successfully placed queens in n rows (0...n-1);
        count ++;
        // print the board
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 1)
                {
                    cout << "Q ";
                }
                else
                {
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        cout << endl;

        return false;       // when finding all ways in which N-queen can be placed on board
        // return true;           // when finding single way in which N -queen can be placed on board
    }

    // Recursive Case
    // try to place the queen on current row and call on the remaining part
    for(int col=0; col<n; col++)
    {
        // check if (row,col)th position is safe to place the queen or not
        if(isSafe(board, row, col, n))
        {
            // place the queen - assuming row,col is the right position
            board[row][col] = 1;
            bool didNextQueenGotPlacedOnRemainingBoard = solveNQueens(board, row+1, n);
            if(didNextQueenGotPlacedOnRemainingBoard)
            {
                return true;
            }
            // when (row,col) is not the right position i.e above assumption is wrong
            board[row][col] = 0;   // backtrack
        }
    }
    // when tried for all position in the current row but couldn't place a queen
    return false;
}


// function to drive code
int main()
{
    int n;
    cout << "Enter Number of Queens: ";
    cin >> n;

    char board[20][20] = {0};

    solveNQueens(board, 0, n);
    cout << "Total number of ways to place N-Queens: " << count;

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter Number of Queens: 4
    _ Q _ _ 
    _ _ _ Q 
    Q _ _ _ 
    _ _ Q _ 

    _ _ Q _ 
    Q _ _ _ 
    _ _ _ Q 
    _ Q _ _ 
    Total number of ways to place N-Queens: 2


Case 2:
    Enter Number of Queens: 3
    Total number of ways to place N-Queens: 0


Case 3:
    Enter Number of Queens: 1
    Q 
    Total number of ways to place N-Queens: 1

*/
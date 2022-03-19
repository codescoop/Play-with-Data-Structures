/*
    Topic - Sudoku Solver

    We have (N x N) Sudoku. N is a perfect square.
    write an algorithm which finds a possible solution.

    Note: N x N Grids
          sqrt(N) x sqrt(N) sub grids

    Rules:
    - Every row has numbers from 1 to 9
    - Every col has numbers from 1 to 9
    - Every sub-grid has numbers from 1 to 9

*/

#include <iostream>
#include <cmath>
using namespace std;

// function to check if we can place the number after checking its row, column & subgrid
bool canPlaceNumber(int mat[][9], int i, int j, int n, int number)
{
    for(int x=0; x<n; x++)
    {
        // check for row & column
        if(mat[x][j]==number || mat[i][x]==number)
        {
            return false;
        }
    }
    // check that number should not return in subgrids
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;
    for(int x=sx; x<sx+rn; x++)
    {
        for(int y=sy; y<sy+rn; y++)
        {
            if(mat[x][y] == number)
            {
                return false;
            }
        }
    }
    // if number is not present in row, column & subgrid, then we can place the number i.e return true
    return true;

    /* 
        Formula to find starting coordinate of Subgrids:-
        sx = (i/3)*3;
        sy = (j/3)*3;

        Eg: when i=5, j=3,
            sx = (5/3)*3 = (1)*3 = 3
            sy = (3/3)*3 = (1)*3 = 3
            So, for (5,3) coordinatine, the starting point of the sub-grid is (3,3)
        
            when i=7, j=2,
            sx = (7/3)*3 = (2)*3 =  6
            sy = (2/3)*3 = (0)*3 =  0
            So, for (7,2) coordinatine, the starting point of the sub-grid is (6,0)

                  0    1    2      3    4    5      6    7    8  
              0|_00_|____|____|  _03_|____|____|  _06_|____|____|
              1|____|____|____|  ____|____|____|  ____|____|____|
              2|____|____|____|  ____|____|____|  ____|____|____|
                                                                 
              3|_30_|____|____|  _33_|____|_ij_|  _36_|____|____|     (i,j)   = (5,3) sx=(5/3)*3 = 3
              4|____|____|____|  ____|____|____|  ____|____|____|                     sy=(3/3)*3 = 3
              5|____|____|____|  ____|____|____|  ____|____|____|     (sx,sy) = (3,3)
                                                                 
              6|_60_|____|____|  _63_|____|____|  _66_|____|____|
              7|____|____|_ij_|  ____|____|____|  ____|____|____|     (i,j)   = (7,2) sx=(7/3)*3 = 6
              8|____|____|____|  ____|____|____|  ____|____|____|                     sy=(2/3)*3 = 0
                                                                      (sx,sy) = (6,0)

        So, General Formula: 
        when we have N*N Grids, then the starting-coordinate (sx,sy) of subgrid, for any cell (i,j) will be: 
        sx = (i/sqrt(N))*sqrt(N);
        sy = (j/sqrt(N))*sqrt(N);
    */
}


bool solveSudoku(int mat[][9], int i, int j, int n)
{
    // Base Case
    if (i == n)
    {
        // print the matrix
        for(int i=0; i<n; i++)
        {
            cout << "|";
            for(int j=0; j<n; j++)
            {
                cout << mat[i][j] << "|";
            }
            cout << endl;
        }

        return true;
    }

    // Case when row ends
    if (j == n)
    {
        return solveSudoku(mat, i+1, 0, n);
    }

    // Case when cells are pre-filled. Skip them
    if (mat[i][j] != 0)
    {
        return solveSudoku(mat, i, j+1, n);
    }

    // Recursive Case
    // Fill the current cell with possible options
    for (int number = 1; number <= n; number++)
    {
        if (canPlaceNumber(mat, i, j, n, number))
        {
            // Assume that we are placing the right number
            mat[i][j] = number;

            bool couldWeSolve = solveSudoku(mat,i,j+1,n);
            if(couldWeSolve == true)
            {
                return true;
            }
        }
    }
    // Backtrack - when assumption is wrong
    mat[i][j] = 0;
    return false;
}

// function to drive code
int main()
{
    int n = 9;
    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };

    // print sudoku
    for(int i=0; i<n; i++)
    {
        cout << "|";
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] == 0)
            {
                cout << "_" << "|";
            }
            else
            {
                cout << mat[i][j] << "|";
            }
        }
        cout << endl;
    }

    cout << "\nSolved Sudoku: \n";
    solveSudoku(mat, 0, 0, n);
    cout << endl;
    return 0;
}

/*
OUTPUT:
    |5|3|_| _|7|_| _|_|_|
    |6|_|_| 1|9|5| _|_|_|
    |_|9|8| _|_|_| _|6|_|

    |8|_|_| _|6|_| _|_|3|
    |4|_|_| 8|_|3| _|_|1|
    |7|_|_| _|2|_| _|_|6|
    
    |_|6|_| _|_|_| 2|8|_|
    |_|_|_| 4|1|9| _|_|5|
    |_|_|_| _|8|_| _|7|9|

    Solved Sudoku: 
    |5|3|4| 6|7|8| 9|1|2|
    |6|7|2| 1|9|5| 3|4|8|
    |1|9|8| 3|4|2| 5|6|7|

    |8|5|9| 7|6|1| 4|2|3|
    |4|2|6| 8|5|3| 7|9|1|
    |7|1|3| 9|2|4| 8|5|6|
    
    |9|6|1| 5|3|7| 2|8|4|
    |2|8|7| 4|1|9| 6|3|5|
    |3|4|5| 2|8|6| 1|7|9|
*/
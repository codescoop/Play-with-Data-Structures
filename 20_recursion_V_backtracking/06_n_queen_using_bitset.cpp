/*
    Agenda - Clear some of the backtracking concepts

    Questions
    ---------
    N-Queens Problem:
    - print/count 1 config
    - print/count all config

    Approaches
    ---------
    1. Naive Backtracking Approach
    2. Backtracing + Bitset (efficient)
    3. Backtracking + Bitmasks (more efficient)      [Advance Backtracking]
       (i.e how to use bitmask during backtracking)

*/

#include <iostream>
#include <bitset>
using namespace std;

bitset<30> col, d1, d2;
/* 
    Note: - bitset is a class in c++
          - bitset is memory efficient
            Eg: In the above example bitset<30> col, will take memory of 30 bits
                But, if we have to created an array of boolean. Then 1 bool = 8 bits
                So, Then array of size 30 will take 30*8bits memory.
                That's why we will be using bitset
 */

// [Using Bitset Approach] function to place N-queens on NxN board
void solveNQueens_efficient(char board[][20], int r, int n, int &count)                  // r:row | n: total Queens
{
    // Base case
    if(r == n)
    {
        // print the board
        /* for(int i=0; i<n; i++)
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
        cout << endl; */

        count++;
        return;
    }

    // Recursive case
    for(int c=0; c<n; c++)
    {
        // if no queen is placed on the column 'col' & both diagnols 'd1' & 'd2'
        if(!col[c] && !d1[r-c+n-1] && !d2[r+c])
        {
            // placing the queen (i.e 1 means booked)
            col[c] = d1[r-c+n-1] = d2[r+c] = board[r][c] = 1;

            // recursive call on next row
            solveNQueens_efficient(board, r+1, n, count);
            
            // backtracking: unplacing the queen (i.e 0 means available)
            col[c] = d1[r-c+n-1] = d2[r+c] = board[r][c] = 0;
        }
    }

    /* 
        When n=5
                          __0__ __1__ __2__ __3__ __4__ 
        Board[5][5] =   0|_0,0_|_0,1_|_0,2_|_0,3_|_0,4_|
                        1|_1,0_|_1,1_|_1,2_|_1,3_|_1,4_|
                        2|_2,0_|_2,1_|_2,2_|_2,3_|_2,4_|
                        3|_3,0_|_3,1_|_3,2_|_3,3_|_3,4_|
                        4|_4,0_|_4,1_|_4,2_|_4,3_|_4,4_|

         

        For Colums(i,j)
        
        - For every ROW in a for-loop, we can refer bitset for mapping Columns

                _col0 _col1 _col2 _col3 _col4    
          row0 |__0__|__1__|__2__|__3__|__4__|   
          row1 |__0__|__1__|__2__|__3__|__4__|   
          row2 |__0__|__1__|__2__|__3__|__4__|   
          row3 |__0__|__1__|__2__|__3__|__4__|   
          row4 |__0__|__1__|__2__|__3__|__4__|   
        
                                    __0__ __1__ __2__ __3__ __4__
        Bitsets (for column)  =   0|__1__|__0__|__0__|__0__|__1__|
                                               cols              
                                
                                check if (0,1) is available i.e col[0+1] = col[1]. [Yes, its available]
                                check if (3,1) is available i.e col[3+1] = col[4]. [No, its not available]




        For Diagnals(i,j) from Left to Right:
        
        - i+j can be 0,1,2,3,4,5,6,7,8

             __0__ __1__ __2__ __3__ __4__        Eg: 0 = (0,0) 
            |_0,0_|_0,1_|_0,2_|_0,3_|_0,4_|4          1 = (1,0),(0,1) 
            |_1,0_|_1,1_|_1,2_|_1,3_|_1,4_|5          2 = (2,0),(1,1),(0,2) 
            |_2,0_|_2,1_|_2,2_|_2,3_|_2,4_|6          3 = (3,0),(2,1),(1,2),(0,3) 
            |_3,0_|_3,1_|_3,2_|_3,3_|_3,4_|7          4 = (4,0),(3,1),(2,2),(1,3),(0,4) 
            |_4,0_|_4,1_|_4,2_|_4,3_|_4,4_|8          5 = (4,1),(3,2),(2,3),(4,1)
                                                      6 = (4,2),(3,3)(2,4)
               /   /   /   /     Right                7 = (4,3),(3,4)
                  /   /   /   /                       8 = (4,4)
                     /   /   /   /                  
               Left     /   /   /   /               

        - So, each diagnols can be mapped with unique intergers.
        
                                     __0__ __1__ __2__ __3__ __4__ __5__ __6__ __7__ __8__
        Bitsets (for diagnols) =   0|__0__|__0__|__0__|__0__|__0__|__1__|__0__|__1__|__0__|
                                                         d1 (diagnols)                     
                                
                                check if (2,1) is available i.e d1[2+1] = d1[3]  [Yes, its available]
                                check if (4,3) is available i.e d1[4+3] = d1[7]  [No, its not available]




        For Diagnals(i,j) Right to Left:
        - i-j can be 0,1,2,3,4,5,6,7,8
                                                                                          Mapping with 0 to 8
              __0__ _-1__ _-2__ _-3__ _-4__      Eg:-4 = (0,4)                          | 0 => (0-4)+4
            0|_0,0_|_0,1_|_0,2_|_0,3_|_0,4_|        -3 = (0,3),(1,4)                    | 1 => (0-3)+4, (1-4)+4
            1|_1,0_|_1,1_|_1,2_|_1,3_|_1,4_|        -2 = (0,2),(1,3),(2,4)              | 2 => .....
            2|_2,0_|_2,1_|_2,2_|_2,3_|_2,4_|        -1 = (0,1),(1,2),(2,3),(3,4)        | 3 => .....
            3|_3,0_|_3,1_|_3,2_|_3,3_|_3,4_|         0 = (0,0),(1,1),(2,2),(3,3),(4,4)  | 4 => .....
            4|_4,0_|_4,1_|_4,2_|_4,3_|_4,4_|         1 = (1,0),(2,1),(3,2),(4,3)        | 5 => .....
                                                     2 = (2,0),(3,1)(4,2)               | 6 => .....
                Right     \   \   \   \              3 = (3,0),(4,1)                    | 7 => .....
                       \   \   \   \                 4 = (4,0)                          | 8 => (4-0)+4
                    \   \   \   \                      
                 \   \   \   \      Left               
        
        - Now, the range is -4 to 4. Since, we cann't keep a array with -ve index.
          So, we keep the range from 0 to 8 and 
              we will map -4 to 0 and 4 to 8
          Thus to achive this, we will do:
                          =  r - c + 4
                          =  r - c + (n-1)
        
                                     __0__ __1__ __2__ __3__ __4__ __5__ __6__ __7__ __8__
        Bitsets (for diagnols) =   0|__0__|__0__|__0__|__0__|__0__|__1__|__0__|__1__|__0__|
                                                         d2 (diagnols)                     
                                
                                check if (1,3) is available i.e d2[1-3+4] = d2[2] [Yes, its available]
                                check if (4,1) is available i.e d2[4-1+4] = d2[7] [No, its not available]

    */
}



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


// [Naive Backtracking Approach] function to place N-queens on NxN board
int solveNQueens(char board[][20], int row, int n)                      // n: total queens
{
    // Base Case
    if(row == n)
    {
        // you have successfully placed queens in n rows (0...n-1);
        // print the board
        /* for(int i=0; i<n; i++)
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
        cout << endl; */
        return 1;
    }

    // Recursive Case
    int count = 0;
    // try to place the queen on current row and call on the remaining part
    for(int col=0; col<n; col++)
    {
        // check if (row,col)th position is safe to place the queen or not
        if(isSafe(board, row, col, n))
        {
            // place the queen - assuming row,col is the right position
            board[row][col] = 1;
            count += solveNQueens(board, row+1, n);
            
            // when (row,col) is not the right position i.e above assumption is wrong
            board[row][col] = 0;   // backtrack
        }
    }
    return count;
}


// function to drive code
int main()
{
    int n;
    cout << "Enter Number of Queens: ";
    cin >> n;

    char board[20][20] = {0};
    int count = 0;

    // count = solveNQueens(board, 0, n);                  // using Naive Backtracking Approach
    solveNQueens_efficient(board, 0, n, count);            // using Bitset Approach

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
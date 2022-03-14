/*
    Topic - Recursion Rat in a Maze

    Given a (M x N) matrix, with some cells as blocked you have to-
    1. find path from source to destination
    2. count the number of path from source to destination
    3. print all possible paths
    Given the rat can move only forward and down.

           source_________
           (0,0)|_|_|_|x|_|
                |_|x|_|_|_|
                |x|_|_|x|_|
                |_|_|_|_|_|(M-1, N-1)
                           destination

    Solution
          _________                     _________
    (0,0)|1|1|1|x|_|              (0,0)|1|1|1|x|_|
         |0|x|1|_|_|                   |0|x|1|1|1|
         |x|_|1|x|_|                   |x|_|_|x|1|
         |_|_|1|1|1|(M-1, N-1)         |_|_|_|_|1|(M-1, N-1)

*/

#include <iostream>
using namespace std;

// function to print all possible paths
bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n)
{
    // base case
    // print path if exists
    if (i == m-1 && j == n-1)
    {
        soln[m-1][n-1] = 1;
        // print path
        for (int i = 0; i <= m-1; i++){
            for (int j = 0; j <= n-1; j++)
            {
                cout << soln[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    
    // rat should be inside grid
    if (i > m-1 || j > n-1)
    {
        return false;
    }

    // check path blockage
    if (maze[i][j] == 'x')
    {
        return false;
    }

    // recursion case
    // assume path exists thought current cell
    soln[i][j] = 1;

    // recursive call
    bool rightSuccess = ratInMaze(maze, soln, i, j+1, m, n);
    bool downSuccess = ratInMaze(maze, soln, i+1, j, m, n);
    
    // backtracking - uncheck the cell, when returing back from the recursive call
    soln[i][j] = 0;
    
    // if we found path from right side Or down side
    if (rightSuccess || downSuccess)
    {
        return true;
    }
    // if we doesn't found any path from right side or down side
    return false;
}

// function to drive code
int main()
{
    char maze[10][10] = {"000x0",
                         "0x000",
                         "x00x0",
                         "00000"};

    int soln[10][10] = {0};
    int m=4, n=5;

    cout << "Maze: \n";
    for (int i = 0; i <= m-1; i++)
    {
        for (int j = 0; j <= n-1; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    cout << "Path: \n";
    bool ans = ratInMaze(maze, soln, 0, 0, m, n);

    if (ans == false)
    {
        cout << "Path doesn't exist." << endl;
    }

    return 0;
}

/*
OUTPUT:
    Maze: 
         0 0 0 x 0 
         0 x 0 0 0 
         x 0 0 x 0 
         0 0 0 0 0 

    Path: 
         1 1 1 0 0 
         0 0 1 1 1 
         0 0 0 0 1 
         0 0 0 0 1 

         1 1 1 0 0 
         0 0 1 0 0 
         0 0 1 0 0 
         0 0 1 1 1 
*/
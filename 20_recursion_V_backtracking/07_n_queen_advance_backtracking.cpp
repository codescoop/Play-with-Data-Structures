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
using namespace std;

int n;
int count = 0, DONE;
// rowmask denote which positions(columns) in all row are filled
// ld, rd denotes unsafe positions along diagnols for the current row
// DONE is vector of all 11111 (n times 1)
// safe denotes the cols which are safe in current rowss


// More optimisized n queen code !
void solveNQueens(int rowMask, int ld, int rd)
{
    // Base Case
    if(rowMask == DONE)
    {
        count++;
        return;
    }

    // Recursive Case
    int safe = DONE & (~(rowMask | ld | rd));
    while(safe)
    {
        int p = safe & (-safe);
        safe = safe -p;
        solveNQueens(rowMask | p, (ld | p) << 1, (rd | p) >> 1);
    }
}


// function to drive code
int main()
{
    int n;
    cout << "Enter Number of Queens: ";
    cin >> n;

    DONE = ((1 << n) - 1);

    solveNQueens(0, 0, 0);                                         // using Bitmask Approach
    cout << "Total number of ways to place N-Queens: " << count;

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter Number of Queens: 8
    Total number of ways to place N-Queens: 92

Case 2:
    Enter Number of Queens: 3
    Total number of ways to place N-Queens: 0

Case 3:
    Enter Number of Queens: 1
    Total number of ways to place N-Queens: 1
*/
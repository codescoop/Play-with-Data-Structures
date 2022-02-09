/*
    Topic - Tiling Problem (Recursion)

    # Place the Tiles
    - Given a wall of size 4 X N, and tiles of size (1,4) and (4,1).
    - In how many ways you can build the wall?

        __________________________                             _
     4 |                          |                          4| |
       |                          |                           | |
       |                          |       ______              | |
       |__________________________|     1|______|             |_|
                                 N             4                1

                 wall                      tile-1            tile-2

    Eg: Input   : n = 4
        Output  : 5
        Explanation:  For a 2 x 4 wall, there are 5 ways
                      All 4 vertical (1 way)
                      All 4 horizontal (1 way)
                      2 vertical and 2 horizontal (3 ways)
*/

#include <iostream>
using namespace std;

// function to get total number of ways to build wall of size (4 x N)
int getNoOfWays(int n)
{
    // base case
    if(n <= 3)
    {
        return 1;
    }
    // rec case:
    int x = getNoOfWays(n-1);
    int y = getNoOfWays(n-4);

    return x+y;

}


// function to drive code
int main()
{
    int width;
    cout << "Enter wall width [4 x N]: ";
    cin >> width;

    cout << "Number ways to build wall: ";
    cout << getNoOfWays(width);

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter wall width [4 x N]: 1
    Number ways to build wall: 1

Case 2:
    Enter wall width [4 x N]: 4
    Number ways to build wall: 2
    
Case 3:
    Enter wall width [4 x N]: 5
    Number ways to build wall: 3
*/
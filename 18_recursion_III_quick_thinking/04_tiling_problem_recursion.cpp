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

    Eg: Input   : n = 5
        Output  : 3
        Explanation:  For a [4 x 5] wall, there are 3 ways:
                      - All 5 vertical tiles (1 way)
                      - 1 vertical and 4 horizontal (1 ways)
                      - 4 horizontal and 1 vertical (1 ways)
                        _________           _________                _________  
                     4 | | | | | |       4 |_______| |            4 | |_______| 
                       | | | | | |         |_______| |              | |_______| 
                       | | | | | |         |_______| |              | |_______| 
                       |_|_|_|_|_|         |_______|_|              |_|_______| 
                                N=5                 N=5                      N=5
                        
                     5-vertical tiles   4-horizontal & 1-vertical  1-vertical & 4-horizontal

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
    /* 
        APPROACH:

        When we place a tile of size [4x1] on wall [4xN], then the pending space is n-1
        Similarly, When we place a tile of size [1x4] on wall [4xN], then the pending space is n-4
        Eg: 
                    ______________________________            ______________________________     
                 4 | |                            |        4 |____|                         |    
                   | |                            |          |____|                         |    
                   | |                            |          |____|                         |    
                   |_|____________________________|          |____|_________________________|    
                                                 N                                         N     
                   <-><--------------------------->           <--> <------------------------>    
                    1              N-1                         4              N-4                
        
        Thus, f(n) = f(n-1) + f(n-4)
    */
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

Case 4:
    Enter wall width [4 x N]: 6
    Number ways to build wall: 4
*/
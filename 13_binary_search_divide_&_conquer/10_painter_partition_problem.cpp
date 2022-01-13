/* 
    Topic - Painter's Partition Problem
    
    You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and 
    you are also given how much time a painter takes to paint 1 unit of board. 
    You have to get this job done as soon as possible under the constraints that any painter will 
    only paint contiguous sections of board. Return the ans % 10000003

    Input Format: First line contains three space seperated integers N,K and T ,where
                  T = Time taken to print each board by one painter
                  K = No of painters available ,
                  N = Size of array,
                  Next line contains N space seperated positive integers denoting size of N boards.

    Constraints:  1 <= N,K,T,Li <= 100000

    Output Format: Return minimum time required to paint all boards % 10000003.

    Sample Input: 5 
                  2
                  2
                  1 10

    Sample Output: 50
    
    Explanation: The first painter can paint the first board in 5 units of time and the 
                 second painter will take 50 units of time to paint the second board. 
                 Since both can paint simultaneously , the total time required to paint both 
                 the boards is 50.
*/

#include <iostream>
#include <climits>
using namespace  std;

// function to check if it is possible to paint all boards in the given time
bool isPossible(int board[], int totalBoard, int totalPainter, int given_time){
    // code
    return false/true;
}


// function to find minimum time taken by painter's to paint all boards
int getMinTime(int *board, int totalBoard, int totalPainter){
    /* Assuming the search space for Number of Minutes & 
       appling binary search on this time range */

    // find sum of all board length
    int sum_boards_length = 0;
    for(int idx=0; idx<=totalBoard-1; idx++){
            sum_boards_length += board[idx] ;
    }

    // Max time taken by cook (i.e Time take to cook all prata by the cook having last rank)
    int time = 1;
    int time_taken_paint_all_board_by_single_painter = sum_boards_length * time;

    int start = 1;
    int end = time_taken_paint_all_board_by_single_painter;
    int timeTaken = INT_MAX;

    while(start<=end)
    {
        int mid = (start+end)/2;

        // check if it is possible to paint all boards in given time (i.e mid value)
        int status = isPossible(board, totalBoard, totalPainter, mid);

        if(status){
            // if it is possible to paint all boards in x minutes
            timeTaken = min(timeTaken, mid);     // store minimum value from the eligible time values
            end = mid-1;
        }else{
            // if it is not possible to paint all boards in x minutes
            start = mid+1;
        }
    }
    return timeTaken;
}


// function to drive code
int main(){
    int testcases;
    cout << "Enter total testcases: ";
    cin >> testcases;

    while(testcases){
        int totalPainter, totalBoard;
        cout << "Enter number of Painter's & Board: ";
        cin >> totalPainter >> totalBoard;
        
        int board[totalBoard];
        cout << "Enter length of boards: ";
        for(int idx=0; idx<=totalBoard-1; idx++){
            cin >> board[idx] ;
        }

        // finding minimum tme required to paint all boards
        int timeTaken = getMinTime(board, totalBoard, totalPainter);
        
        cout << "Minimum time to paint all boards: ";
        cout << timeTaken << endl;

        testcases--;
    }

    return 0;
}


/* 
OUTPUT:

   
*/
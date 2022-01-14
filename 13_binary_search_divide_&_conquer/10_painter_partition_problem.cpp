/* 
    Topic - Painter's Partition Problem
    
    Given K painters to paint N boards where each painter takes 1 unit of time to paint 1 unit of boards 
    i.e. if the length of a particular board is 5, it will take 5 units of time to paint the board. 
    Compute the minimum amount of time to paint all the boards.

    Note that: Every painter can paint only contiguous segments of boards.
    A board can only be painted by 1 painter at maximum.

    Input Format: First line contains K which is the number of painters. 
                  Second line contains N which indicates the number of boards. 
                  Third line contains N space separated integers representing the length of each board.

    Constraints: 1 <= K <= 10
                 1 <= N <= 10
                 1<= Length of each Board <= 10^8

    Output Format: Output the minimum time required to paint the board.

    Sample Input: 2
                  2
                  1 10

    Sample Output : 10
*/

#include <iostream>
#include <climits>
using namespace  std;

// function to check if it is possible to paint all boards in the given time
bool isPossible(int board[], int totalBoard, int totalPainter, int given_time)
{
    int time_taken_per_unit = 1;     // painter takes 1 unit of time to paint 1 unit of boards

    int painter_used = 1;
    int time_taken_till_now = 0;
    for(int idx=0; idx<= totalBoard-1; idx++)
    {
        // when board length is greater than allocated time
        if(board[idx] > given_time){
            return false;
        }

        // time taken to paint new board
        int time_taken_for_new_board = board[idx]*time_taken_per_unit;

        if((time_taken_till_now + time_taken_for_new_board) <= given_time )
        {
            time_taken_till_now += time_taken_for_new_board;
        }
        else
        {
            painter_used++;
            time_taken_till_now = time_taken_for_new_board;
            if(painter_used > totalPainter){
                return false;
            }
        }
    }
    return true;
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

    // Max time taken by painter (i.e Time take to paint all boards by single painter)
    int time_taken_per_unit = 1;    // painter takes 1 unit of time to paint 1 unit of boards
    int time_taken_to_paint_all_board_by_single_painter = sum_boards_length * time_taken_per_unit;

    int start = 1;
    int end = time_taken_to_paint_all_board_by_single_painter;
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

    Enter total testcases: 2

    Enter number of Painter's & Board: 2 2
    Enter length of boards: 1 10
    Minimum time to paint all boards: 10

    Enter number of Painter's & Board: 2 3
    Enter length of boards: 10 11 10
    Minimum time to paint all boards: 21

*/
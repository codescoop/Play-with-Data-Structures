/*  
    Wave Print of 2D Array
 */

#include <iostream>
using namespace std;

int main(){
    int arr[1000][1000] = {0};
    int rows, cols;
    cout << "Enter Array Rows & Cols: ";
    cin >> rows >> cols;

    int val=1;
    for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            arr[row][col] = val++;            // assigning & incrementing value
            cout << arr[row][col] << " ";     // printing array
        } 
        cout << endl;
    }

    // wave print
    cout << "Wave Print: ";
    for(int col=0; col<cols; col++){
        if(col%2 == 0){
            //Even Cols (Top Down Direction)
            for(int row=0; row<rows; row++){
                cout << arr[row][col] << " ";
            }
        }else{
            //Odd Cols (Bottom Up Direction)
            for(int row=rows-1; row>=0; row--){
                cout << arr[row][col] << " ";
            }
        }
        cout << " ";
    }
    cout << endl;

    return 0;
}

/* 
OUTPUT:

Case1:
    Enter Array Rows & Cols: 3 3
    1 2 3 
    4 5 6 
    7 8 9 
    Wave Print: 1 4 7  8 5 2  3 6 9

Case2:
    Enter Array Rows & Cols: 3 6
     1  2  3  4  5  6 
     7  8  9 10 11 12 
    13 14 15 16 17 18 
    Wave Print: 1 7 13  14 8 2  3 9 15  16 10 4  5 11 17  18 12 6  
*/
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
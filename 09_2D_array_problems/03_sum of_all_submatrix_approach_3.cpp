/* 
    Sum of All Submatrix from a given Matrix (Approach-3)
    - Time Complexity - O(n^2)
    - Space Complexity - O(1)
*/

#include <iostream>
using namespace std;

int sumOfSubmatrix(int **arr, int rows, int cols){
    int sum = 0;
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            int tl = (row+1)*(col+1);             // tl: top left
            int br = (rows-row)*(cols-col);       // br: bottom right
            sum += (tl * br)*arr[row][col];
        }
    }
    return sum;
}

int main(){
    int rows, cols;
    cout << "Enter matrix [Rows & Columns]: ";
    cin >> rows >> cols;

    int **arr = new int*[rows];
    for(int idx=0; idx<=rows-1; idx++){
        arr[idx] = new int[cols];
    }

    // Taking matrix input
    cout << "Enter matrix values: \n";
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cin >> arr[row][col];
        }
    }

    cout << "Sum of Submatrix: " << sumOfSubmatrix(arr,rows,cols) << endl;

    return 0;
}
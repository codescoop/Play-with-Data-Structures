/*
    Problem Name: Spiral Print Anticlockwise

    Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

    Input Format: Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).
    
    Constraints: Both M and N are between 1 to 10.

    Output Format: All M * N integers separated by commas with 'END' written in the end(as shown in example).

    Sample Input:   4 4
                    11 12 13 14
                    21 22 23 24
                    31 32 33 34
                    41 42 43 44

    Sample Output:  11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END

    Explanation: For spiral level anti-clockwise traversal, 
                 Go for first column-> last row ->last column-> first row and 
                 then do the same traversal for the remaining matrix .
*/

#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter Matrix [Rows & Cols]: ";
    cin >> rows >> cols;

    int arr[rows][cols];
    cout << "Enter matrix values: \n";
    for (int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cin >> arr[row][col];
        }
    }

    cout << "Array in spiral form anticlock wise: ";
    
    int rowStart = 0;
    int rowEnd = rows-1;
    int colStart = 0;
    int colEnd = cols-1;

    while(rowStart<=rowEnd && colStart<=colEnd){
        // first column
        for (int row=rowStart; row<=rowEnd; row++){
                cout << arr[row][colStart] << ", ";
        }
        colStart++;
        // last row
        for (int col=colStart; col<=colEnd; col++){
                cout << arr[rowEnd][col] << ", ";
        }
        rowEnd--;
        // last column
        if(colStart <= colEnd){
            for (int row=rowEnd; row>=rowStart; row--){
                    cout << arr[row][colEnd] << ", ";
            }
            colEnd--;
        }
        // first row
        if(rowStart <= rowEnd){
            for (int col=colEnd; col>=colStart; col--){
                    cout << arr[rowStart][col] << ", ";
            }
            rowStart++;
        }
    }

    cout << "END" << endl;

	return 0;
}


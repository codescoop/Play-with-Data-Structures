/*
    Array - Wave print column wise
    
    Take as input a two-d array. Wave print it column-wise.
    
    Input Format:  Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

    Constraints:  Both M and N are between 1 to 10.
    
    Output Format: All M * N integers seperated by commas with 'END' wriiten in the end(as shown in example).
    
    Sample Input:   4 4
                    11 12 13 14
                    21 22 23 24
                    31 32 33 34
                    41 42 43 44
    
    Sample Output: 11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14, END

*/

#include <iostream>
using namespace std;

int main() {
	int rows, cols;
    cout << "Enter array [Rows & Cols]: ";
    cin >> rows >> cols;

    int arr[rows][cols];
    cout << "Enter array elements: \n";
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cin >> arr[row][col];
            
        }
    }

    //wave pattern
    cout << "Wave Pattern: ";
    for(int col=0; col<=cols-1; col++){
        if(col%2 == 0){
            for(int row=0; row<=rows-1; row++){
                cout << arr[row][col] << ", ";
            }
        }else{
            for(int row=rows-1; row>=0; row--){
                cout << arr[row][col] << ", ";
            }
        }
    }
    cout << "END" << endl;
	return 0;
}
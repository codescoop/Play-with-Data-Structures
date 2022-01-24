/*
    Problem Name: Rotate Image(N x N Array)

    Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

    Input Format: First line contains a single integer N. Next N lines contain N space separated integers.

    Constraints: N < 1000

    Output Format: Print N lines with N space separated integers of the rotated array.

    Sample Input:   4
                    1 2 3 4
                    5 6 7 8
                    9 10 11 12
                    13 14 15 16


    Sample Output:  4 8 12 16 
                    3 7 11 15 
                    2 6 10 14 
                    1 5 9 13 

    Explanation: Rotate the array 90 degrees anticlockwise.
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

    // Step:1 Reverse the column
    for(int idx=0; idx<=rows-1; idx++){
        int start = 0;
        int end = cols-1;
        while(start<end){
            swap(arr[idx][start], arr[idx][end]);
            start++;
            end--;
        }
    }

    // Step:2 Transpose the matrix
    for (int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            if(row > col){
                swap(arr[row][col], arr[col][row]);
            }
        }
    }

    // Print array after 90 degree rotation
    cout << "Array in spiral form anticlock wise: \n";
    for (int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

	return 0;
}


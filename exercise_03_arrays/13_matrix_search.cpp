/*
    Problem Name: Matrix Search

    Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . 
    Find if element x is present in the matrix or not.
    
    Input Format: First line consists of two space separated integers N and M, 
                  denoting the number of element in a row and column respectively. 
                  Second line of each test case consists of N*M space separated integers 
                  denoting the elements in the matrix in row major order. 
                  Third line of each test case contains a single integer x, the element to be searched.

    Constraints: 1 <= N, 
                 M <= 30 
                 0 <= A[i] <= 100

    Output Format: Print 1 if the element is present in the matrix, else 0.

    Sample Input:   3 3
                    3 30 38
                    44 52 54
                    57 60 69
                    62


    Sample Output:  0

    Explanation: Search the element in the sorted matrix. 
                 If the element is present print 1 otherwise print 0. 
                 In the sample input,in first case 62 is not present in the matrix so 0 is printed. 
                 Similarly, for second case 55 is present in the matrix so 1 is printed.
*/

#include <iostream>
using namespace std;

// using Staircase Search Approach
int searchMatrix(int **arr, int rows, int cols, int key){
    int rowStart = 0;
    int colEnd = cols-1;
    while(rowStart <= rows-1 && colEnd >= 0){
        if(key == arr[rowStart][colEnd]){
            return 1;
        }else if(key < arr[rowStart][colEnd]){
            colEnd--;
        }else{
            rowStart++;
        }
    }
    return 0;
}

int main() {
    int rows, cols;
    cout << "Enter Matrix [Rows x Cols]: ";
    cin >> rows >> cols;

    int **arr = new int*[rows];
    for(int row=0; row<=rows; row++){
        arr[row] = new int[cols];
    }

    cout << "Enter Matrix elements: \n";
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cin >> arr[row][col];
        }
    }

    int key;
    cout << "Enter Search Key: ";
    cin >> key;

    // Search Matrix
    cout << "Output: " << searchMatrix(arr, rows, cols, key);
    cout << endl;

	return 0;
}


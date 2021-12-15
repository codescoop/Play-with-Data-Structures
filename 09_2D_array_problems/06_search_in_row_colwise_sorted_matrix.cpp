/*
    Search in Row and Col wise Sorted Matrix

    Sample Input: 3 5
                  10 20 30 40
                  15 25 35 45
                  27 29 37 48
                  key: 29

    Sample Output: 2,0
*/

#include <iostream>
using namespace std;

// Linear Search [Time complexity - O(n*m)]
void matrixLinearSearch(int **arr, int rows, int cols, int key)
{
    int rowIdx = -1;
    int colIdx = -1;
    for (int row = 0; row <= rows - 1; row++){
        for (int col = 0; col <= cols - 1; col++){
            if(key == arr[row][col]){
                rowIdx = row;
                colIdx = col;
                break;
            }
        }
    }
    if(rowIdx == -1){
        cout << "[Linear Search] Value Not Found" << endl;
    }else{
        cout << "[Linear Search] Value Found at Index: " << rowIdx << "," << colIdx << endl;
    }
}

// Binary Search  [Time Complexity - O(n*log2m) ]
void matrixBinarySearch(int **arr, int rows, int cols, int key)
{
    for (int row = 0; row <= rows - 1; row++){
            int start = 0;
            int end = cols-1;
            while(start<=end){
                int mid = (start+end)/2;
                if(key == arr[row][mid]){
                    cout << "[Binary Search] Value Found at Index: " << row << "," << mid << endl;
                    return;
                }else if(key < arr[row][mid]){
                    end = mid-1;
                }else{
                    start = mid+1;
                }
            }
    }
    cout << "[Binary Search] Value Not Found" << endl;
}

// Stepwise Search || Row & Col wise Search  [Time Complexity - O(n+m)]
void matrixSearch(int **arr, int rows, int cols, int key)
{
    int rowIdx = 0;
    int colIdx = cols-1;
    while(rowIdx <= rows-1 && colIdx >= 0){
        if(key == arr[rowIdx][colIdx]){
            cout << "[Stepwise Search] Value Found at Index: " << rowIdx << "," << colIdx << endl;
                return;
        }else if(key < arr[rowIdx][colIdx]){
            colIdx--;
        }else{
            rowIdx++;
        }
    }
    cout << "[Stepwise Search] Value Not Found" << endl;
}

int main()
{
    int rows, cols;
    cout << "Enter matrix [Rows & Columns]: ";
    cin >> rows >> cols;

    int **arr = new int *[rows];
    for (int idx = 0; idx <= rows - 1; idx++)
    {
        arr[idx] = new int[cols];
    }

    // Taking matrix input
    cout << "Enter matrix values: \n";
    for (int row = 0; row <= rows - 1; row++)
    {
        for (int col = 0; col <= cols - 1; col++)
        {
            cin >> arr[row][col];
        }
    }
    int key;
    cout << "Enter Search key: ";
    cin >> key;

    // Search key
    matrixLinearSearch(arr, rows, cols, key);     // linear search
    matrixBinarySearch(arr, rows, cols, key);     // binary search
    matrixSearch(arr, rows, cols, key);           // stepwise Or row col wise search

    return 0;
}
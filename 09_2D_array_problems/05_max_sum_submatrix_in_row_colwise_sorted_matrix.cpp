/* 
    Maximum Sum Submatrix in Row & in Col wise Sorted Matrix
    
    Sample Input:  3 3
                  -5 -4 -1
                  -3  2  4
                   2  5  8
    
    Sample Output: 19

    Explanation : Create suffix sum matrix
                     8 14 11
                    18 19 12
                    15 13  8
*/

#include <iostream>
#include <climits>
using namespace std;

void printArray(int **arr, int rows, int cols){
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

// creating suffix sum matrix & find the max element
int maxSumSubmatrix(int **arr, int rows, int cols){
    // Col wise addition First
    for(int row=rows-1; row>=0; row--){
        for(int col=cols-2; col>=0; col--){
            arr[row][col] += arr[row][col+1];
        }
    }
    // Row wise addition First
    for(int col=cols-1; col>=0; col--){
        for(int row=rows-2; row>=0; row--){
            arr[row][col] += arr[row+1][col];
        }
    }

    // Display Suffix sum array
    cout << "Suffix Sum Array: \n";
    printArray(arr,rows,cols);
    
    // Finding Max Sum Submatrix
    int result = INT_MIN;
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            result = max(result,arr[row][col]);
        }
    }

    return result;
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

    // Max Sum Submatric
    int result = maxSumSubmatrix(arr, rows, cols);

    cout << "Max Sum Submatrix: " << result << endl;

    return 0;
}

/* 
OUTPUT:
    Enter matrix [Rows & Columns]: 3 3

    Enter matrix values: 
    -5 -4 -1
    -3  2  4
     2  5  8

    Suffix Sum Array: 
     8 14 11 
    18 19 12 
    15 13  8 

    Max Sum Submatrix: 19
*/
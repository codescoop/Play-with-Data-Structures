/* 
    Sum of All Submatrix from a given Matrix (Approach-2)
    - Prefix Sum Matrix Approach
      Time Complexity - O(n^4)
      Space Complexity - O(n^2)

    Sample Input: 2 2
                  1 1
                  1 1

    Sample Output: 16
*/

#include <iostream>
using namespace std;

/*  A simple solution is to find psa[i][j] by traversing and adding values from a[0][0] to a[i][j]. 
    Time complexity of this solution is O(Row*Col*Row*Col).
 */
void prefixSumMatrix1(int **arr, int rows, int cols, int **psa){
    // Copy first row of arr[][] to psa[][]
    for (int col=0; col<cols; col++)
        psa[0][col] = arr[0][col];

    // Do row wise sum
    for (int row=1; row<rows; row++)
        for (int col=0; col<cols; col++)
            psa[row][col] = arr[row][col] + psa[row-1][col];

    // Do column wise sum
    for (int row=0; row<rows; row++)
        for (int col=1; col<cols; col++)
            psa[row][col] += psa[row][col-1];
    
    // Display values of psa array
    cout << "Prefix Sum Matrix: \n";
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cout << psa[row][col] << " ";
        }
        cout << endl;
    }
}

/*  An efficient solution is to use previously computed values to compute psa[i][j].
    Here if we simply add psa[i][j-1] and psa[i-1][j], we get sum of elements from a[0][0] to a[i-1][j-1] twice, 
    So we subtract psa[i-1][j-1]. 
*/
void prefixSumMatrix2(int **arr, int rows, int cols, int **psa){
    // corner case [row=col=0]
    psa[0][0] = arr[0][0];
    // For first row [row=0 & col>0]
    for(int col=1; col<=cols-1; col++){
        psa[0][col] = psa[0][col-1] + arr[0][col]; 
    }
    // For first col [row>0 & col=0]
    for(int row=1; row<=rows-1; row++){
        psa[row][0] = psa[row-1][0] + arr[row][0];
    }
    // General formula for other case (i,j)
    for(int row=1; row<=rows-1; row++){
        for(int col=1; col<=cols-1; col++){
            psa[row][col] = psa[row-1][col] + psa[row][col-1] - psa[row-1][col-1] +arr[row][col];
        }
    }
    // Display values of psa array
    cout << "Prefix Sum Matrix: \n";
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cout << psa[row][col] << " ";
        }
        cout << endl;
    }
}

/*  A O(1) time function to compute sum of a submatrix 
    between (tli, tlj) and (bri, brj) using prefixSumArray[][]
    which is built by the prefixSumMatrix function
 */
int submatrixSum(int **psa, int tli, int tlj, int bri, int brj){
    // result is now sum of elements between (0, 0) and (bri, brj)
    int sum = psa[bri][brj];

    // Remove elements between (0, 0) and (tli-1, brj)
    if (tli > 0)
       sum = sum - psa[tli-1][brj];

    // Remove elements between (0, 0) and (bri, tlj-1)
    if (tlj > 0)
       sum = sum - psa[bri][tlj-1];

    // Add psa[tli-1][tlj-1], as elements between (0, 0) & (tli-1, tlj-1) are subtracted twice
    if (tli > 0 && tlj > 0)
       sum = sum + psa[tli-1][tlj-1];

    return sum;
}

// Function to calculate Sum of All Submatrix
void sumOfAllSubmatrix(int **psa, int rows, int cols){
    int sum = 0;
    // All possible pairs of top left corner
    for(int tli=0; tli<=rows-1; tli++){             // tli: Top Left Row Number
        for(int tlj=0; tlj<=cols-1; tlj++){         // tlj: Top Left Column number

           // All possible pairs of bottom right corner
            for(int bri=tli; bri<=rows-1; bri++){             // bri: Bottom Right Row Number
                for(int brj=tlj; brj<=cols-1; brj++){         // brj: Bottom Right Column Number
                    // sum up the elements
                    sum += submatrixSum(psa,tli,tlj,bri,brj);
                }
            }
        }
    }
    cout << "Sum of Sub Matrix: " << sum;
}

// Drive code
int main(){
    int rows, cols;
    cout << "Enter matrix [Rows & Columns]: ";
    cin >> rows >> cols;
    
    int **arr = new int*[rows];
    int **prefixSumArr = new int*[rows];
    for(int idx=0; idx<=rows-1; idx++){
        arr[idx] = new int[cols];
        prefixSumArr[idx] = new int[cols];
    }

    // Taking matrix input
    cout << "Enter matrix values: \n";
    for(int row=0; row<=rows-1; row++){
        for(int col=0; col<=cols-1; col++){
            cin >> arr[row][col];
        }
    }

    // calculating prefix sum matrix
    prefixSumMatrix2(arr, rows, cols, prefixSumArr);
    // prefixSumMatrix1(arr, rows, cols, prefixSumArr);
    
    // calculating sum of submatrix
    sumOfAllSubmatrix(prefixSumArr,rows,cols);

    cout << endl;
    return 0;
}

/* 
OUTPUT:

    Enter matrix [Rows & Columns]: 2 2
    
    Enter matrix values: 
    1 2
    3 4
    
    Prefix Sum Matrix: 
    1 3 
    4 10 
    
    Sum of Sub Matrix: 40
*/
/* 
    Submatrix Sum Query
    - In a given matrix with all integer elements. 
      You will be give Q number of queries & 
      in each query you will be getting 4 intergers [tli,tlj,bri,brj]
      First two integers will be representing Top Left index &
      Second two integers will be representing Bottom Right index.
      You are suppose to find the sum a submatrix for each query.

    Sample Input:   4 5
                    mat[M][N] = {{1, 2, 3, 4, 6},
                                {5, 3, 8, 1, 2},
                                {4, 6, 7, 5, 5},
                                {2, 4, 8, 9, 4} };
                    Query1: tli = 0, tlj = 0, rbi = 1, rbj = 1
                    Query2: tli = 2, tlj = 2, rbi = 3, rbj = 4
                    Query3: tli = 1, tlj = 2, rbi = 3, rbj = 3;

    Sample Output:
                    Query1: 11  // Sum between (0, 0) and (1, 1)
                    Query2: 38  // Sum between (2, 2) and (3, 4)
                    Query3: 38  // Sum between (1, 2) and (3, 3)
*/

#include <iostream>
using namespace std;


/*  An efficient solution is to use previously computed values to compute psa[i][j].
    Here if we simply add psa[i][j-1] and psa[i-1][j], we get sum of elements from a[0][0] to a[i-1][j-1] twice, 
    So we subtract psa[i-1][j-1]. 
*/
   void prefixSumMatrix(int **arr, int rows, int cols, int **psa){
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
    // Dispaly values of psa array
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
    prefixSumMatrix(arr, rows, cols, prefixSumArr);
    
    // Taking queries input
    int queries, tli, tlj, bri, brj, result;
    cout << "Enter total number of queries: ";
    cin >> queries;
    for(int idx=0; idx<=queries-1; idx++){
        cout << "Enter index: ";
        cin >> tli >> tlj >> bri >> brj;
        result = submatrixSum(prefixSumArr,tli,tlj,bri,brj);
        cout << result << endl;
    }

    return 0;
}
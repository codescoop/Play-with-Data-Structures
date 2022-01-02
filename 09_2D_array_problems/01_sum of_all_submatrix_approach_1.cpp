/* 
    Sum of All Submatrix from a given Matrix (Approach-1)
    - Brute Force Approach
      Time Complexity - O(n^6)
      Space Complexity - O(1)
    
    Sample Input: 3 3
                  1 1 1
                  1 1 1
                  1 1 1

    Sample Output: 100
*/

#include <iostream>
using namespace std;

void sumOfSubmatrix(int **arr, int rows, int cols){
    int sum = 0;
    // All possible pairs of top left corner
    for(int tli=0; tli<=rows-1; tli++){             // tli: Top left row number
        for(int tlj=0; tlj<=cols-1; tlj++){         // tlj: Top left column number

           // All possible pairs of bottom right corner
            for(int bri=tli; bri<=rows-1; bri++){             // bri: Bottom right row number
                for(int brj=tlj; brj<=cols-1; brj++){         // brj: Bottom right column number
 
                    // sum up the elements
                    for(int i=tli; i<=bri; i++){
                        for(int j=tlj; j<=brj; j++){
                            sum += arr[i][j];
                            cout << "[" << i << "," << j << "], "; 
                        }
                    }
                    cout << endl;
                }
            }
            cout << "----------" << endl;
        }
    }
    cout << "\nSum of Sub Matrix: " << sum;
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
    // printAllSubarrays();
    cout << "\nAll Submatrix : \n";
    sumOfSubmatrix(arr,rows,cols);

    cout << endl;
    return 0;
}

/* 
OUTPUT:

    Enter matrix [Rows & Columns]: 2 2
    
    Enter matrix values: 
    1 2
    3 4

    All Submatrix : 
    [0,0], 
    [0,0], [0,1], 
    [0,0], [1,0], 
    [0,0], [0,1], [1,0], [1,1], 
    ----------
    [0,1], 
    [0,1], [1,1], 
    ----------
    [1,0], 
    [1,0], [1,1], 
    ----------
    [1,1], 
    ----------

    Sum of Sub Matrix: 40
 */
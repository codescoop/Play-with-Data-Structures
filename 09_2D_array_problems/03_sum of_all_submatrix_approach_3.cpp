/* 
    Sum of All Submatrix from a given Matrix (Approach-3)
    - Time Complexity - O(n^2)
    - Space Complexity - O(1)

    Approach:
    - In each submatrix the element will be contributing for the sum & Every cell element will be a part
      of more than 1 submatrix.
    - Thus, 
      Contribution of each cell in final sum = (value of cell) * (no of submatrix that cell is a part of)


    >> Now, using permutation & combination we can extract out, How many submatrix any cell (i,j) will be part of.
    
                        (0,0)______________________________________________
                           |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|_______|_______|
         top left area --> |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|_______|_______|
          (X region)       |XXXXXXX|XXXXXXX|XXXXXXX|(i,j)  |YYYYYYY|YYYYYYY|  <-- bottom right area
                           |_______|_______|_______|YYYYYYY|YYYYYYY|YYYYYYY|         (Y region)
                           |_______|_______|_______|YYYYYYY|YYYYYYY|YYYYYYY|
                                                                       (n-1, m-1)

    To define a submatrix we need a pair of Top left coordinate & Bottom right coordinate.
    So, The total number of pairs that can be made form X & Y region , if Top left coordinate form X 
        & bottom right coordinate from the Y   (i.e total submatrix that can be made from X & Y) 
        = X * Y
       
    Total number of cells in Top Left Area  i.e (0,0) to (i,j),
       X = (i+1)*(j+1)
    
    Total number of cells in Bottom Right Area  i.e (i,j) to (n,n),
       Y = (n-i)*(m-j)
    
    number of submatrix in which cell(i,j) is present =  X * Y
                                                      = ((i+1)*(j+1)) * ((n-i)*(m-j))


*/

#include <iostream>
using namespace std;

int sumOfSubmatrix(int **arr, int n, int m){
    int sum = 0;
    for(int i=0; i<=n-1; i++){
        for(int j=0; j<=m-1; j++){
            // total number of cell in the x region (top left area)  i.e (0,0) to (i,j)
            int x = (i+1)*(j+1);
            // total number of cell in the y region (bottom right area) i.e (i,j) to (n,m)
            int y = (n-i)*(m-j);

            // number of submatrix in which cell(i,j) is present = (x * y)
            int total_submatrix = x*y;
            
            // contribution of cell(i,j) in final sum = (value of cell) * (no of submatrix cell [i,j] is a part of)
            sum += arr[i][j] * total_submatrix;
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

/* 
OUTPUT:

    Enter matrix [Rows & Columns]: 2 2

    Enter matrix values: 
    1 2
    3 4

    Sum of Submatrix: 40
*/
/* 
    Topic - Allocating 2D Dynamic Arrays
*/

#include <iostream>
using namespace  std;

int main(){
    int rows, cols;
    cout << "Enter [Rows x Cols] : ";
    cin >> rows >> cols;

    // create an array of row heads
    int **arr = new int*[rows];

    // create a 2D array
    for(int row=0; row<=rows-1; row++){
      arr[row]  = new int[cols];
    }

    // Add value & print array elements
    cout << "Array Elements: \n";
    int val = 1;
    for(int row=0; row<=rows-1; row++){
      for(int col=0; col<=cols-1; col++){
        arr[row][col] = val;
        val++;
        cout << arr[row][col] << " ";
      }
      cout << endl;
    }

    // Free each sub-array
    for(int row=0; row<=rows-1; row++){
      delete[] arr[row];
    }
    //Free the array pointers
    delete[] arr;

    return 0;
}

/* 
OUTPUT: 
    Enter [Rows x Cols] : 3 3
    Array Elements: 
    1 2 3 
    4 5 6 
    7 8 9 
*/
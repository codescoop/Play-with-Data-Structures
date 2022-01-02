/*  
    2D Array Basic
 */

#include <iostream>
using namespace std;

int main(){
    int arr[4][3] = {0,4,5,7};                           // 2D-Array 1

    cout << "arr[4][3] = {0,4,5,7}" <<endl;
    // Iterate over array
    for(int row=0; row<4; row++){
        for(int col=0; col<3;col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    int arr2[1000][1000]= {0};                           // 2D-Array 2
    int m, n;
    cout << "Enter Row & Col for 2D-Array: ";
    cin >> m >> n;                               // user input
    int val=1;
    // Iterate over array
    for(int row=0; row<=m-1; row++){
        for(int col=0; col<=n-1; col++){
            arr[row][col] =  val;                // assigning values
            val++;
            cout << arr[row][col] << " "; 
        }
        cout << endl;
    }

    return 0;
}

/* 
OUTPUT:

    arr[4][3] = {0,4,5,7}
    0 4 5 
    7 0 0 
    0 0 0 
    0 0 0 

    Enter Row & Col for 2D-Array: 3 3
    1 2 3 
    4 5 6 
    7 8 9 
 */
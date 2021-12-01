/*  
    2D Array Basic
 */

#include <iostream>
using namespace std;

int main(){
    int arr[5][3] = {0,4,5,7};                           // 2D-Array 1

    cout << "arr[4][3] = {0,4,5,7}" <<endl;
    // Iterate over array
    for(int row=0; row<=3; row++){
        for(int col=0; col<=2;col++){
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
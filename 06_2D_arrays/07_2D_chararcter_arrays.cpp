/*
    2D Character Array | Strings
*/

#include <iostream>
using namespace std;


int main(){
    
    char arr1[10][10];                                            // example-1
    arr1[0][0] = 'A';

    char arr2[][10] = {{'a','b','\0'},{'d','e','f'}};        // example-2 [character by character]
    cout << arr2[0][1] << endl;       // single character
    cout << arr2[0] << endl;          // complete rows
    cout << arr2[1] << "\n\n";

    char arr3[][10] = {"xyz","hello","hi"};                       // example-3 [string]
    cout << arr3[0][1] << endl;       // single character
    cout << arr3[1] << endl;          // complete row   
    cout << arr3[0] << endl;
    cout << arr3[2] << endl;
   
    return 0;
}
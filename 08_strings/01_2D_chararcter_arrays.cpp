/*
    2D Character Array | Strings
*/

#include <iostream>
using namespace std;


int main(){

    // example-1
    char arr1[10][10];
    arr1[0][0] = 'A';                                 // assign value at first row first character
    cout << "arr1 : " << arr1 << endl;                // print address
    cout << "arr1[0] : " << arr1[0] << endl;          // complete rows (i.e print first character & garbage value)
    cout << "arr1[0][0] : " << arr1[0][0] << "\n\n";  // single character (first row first character)

    // example-2 [character by character]
    char arr2[][10] = {{'a','b','\0'},{'d','e','f'}};
    cout << "arr2[0] : " << arr2[0] << endl;                    // complete rows
    cout << "arr2[1] : " << arr2[1] << endl;
    cout << "arr2[1][1] : " << arr2[1][1] << "\n\n";            // single character (second row second character)

    // example-3 [string]
    char arr3[][10] = {"xyz","hello","hi"};
    cout << "arr3 : " << arr3 << endl;
    cout << "arr3[0] : " << arr3[0] << endl;
    cout << "arr3[1] : " << arr3[1] << endl;          // complete row
    cout << "arr3[2] : " << arr3[2] << endl;
    cout << "arr3[2][0] : " << arr3[2][0] << endl;    // single character (third row first character)

    return 0;
}

/* 
OUTPUT:

    arr1 : 0x7ffe0c90f630
    arr1[0] : A���
    arr1[0][0] : A

    arr2[0] : ab
    arr2[1] : def
    arr2[1][1] : e

    arr3 : 0x7ffe0c90f610
    arr3[0] : xyz
    arr3[1] : hello
    arr3[2] : hi
    arr3[2][0] : h
*/
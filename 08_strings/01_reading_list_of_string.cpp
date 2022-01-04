/*
    Read a list of strings and we will store them in 2D character array
*/

#include <iostream>
using namespace std;


int main(){
    char arr[100][1000];

    int totalStrings;
    cout << "Enter total number of strings: ";
    cin >> totalStrings;
    cin.get();    // To consume the extra "Enter" that is followed after "totalString"

    // Take input
    cout << "Enter your strings: \n";
    for(int row=0; row<=totalStrings-1; row++){ 
        cin.getline(arr[row], 1000);              // Taking input row by row & string in i-th row
    }
    cout << endl;

    // Print out all the strings
    cout << "Output: \n";
    for(int row=0; row<=totalStrings-1; row++){
        cout << arr[row] << endl;
    }

    return 0;
}

/* 
OUTPUT:

    Enter total number of strings: 3 
    
    Enter your strings: 
    ram
    shyam
    raman

    Output: 
    ram
    shyam
    raman
*/
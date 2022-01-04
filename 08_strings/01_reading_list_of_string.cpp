/*
    Read a list of strings and we will store them in 2D character array
    
    - cin                                  : It doesn't read spaces & newline
    - cin.get()                            : Read single character (including spaces & newline)
    - cin.getline(char* ch, int size)      : Read a line from an input stream (Syntax for Character Array)
    - getline(istream& cin, string& str)   : Read a line from an input stream (Syntax for String)
        
        Where,
        char*    : It is a character pointer that points to the array.
        size     : It acts as a delimiter that defines the size of the array means input cannot cross this size.
        string&  : It is a string object, the input is stored in this object after being read from the stream.
        istream& : It is an object of istream class and tells the function about the stream from where to read the input from

    Syntax:
    1. istream& getline (istream& is, string& str, char delim);
    
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
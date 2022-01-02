/*
    Largest String
    - Read N, followed by N strings and print the largest string and its length
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int totalStr;
    cout << "Enter total number of Strings: ";
    cin >> totalStr;

    cin.get();           // to consume extra "\n"

    char currString[1000];
    char maxString[1000];
    int currLen = 0;
    int maxLen = 0;

    cout << "Enter your strings: \n;";
    for(int itr=0; itr<=totalStr-1; itr++){
        cin.getline(currString, 1000);
        currLen = strlen(currString);
        if(currLen > maxLen){
            maxLen = currLen;
            strcpy(maxString,currString);
        }
    }

    cout << "\nMaximum String: " << maxString << "\nlength - " << maxLen << endl;

    return 0;
}

/* 
OUTPUT:

    Enter total number of Strings: 5
    
    Enter your strings:
    raman deep
    amarjeet singh
    ravinder sharma
    mandeep sharma
    ravi juneja

    Maximum String: ravinder sharma
    length - 15
*/
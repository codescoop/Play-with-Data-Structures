/* 
    Tokenization using 'strtok()'

    - char *strtok(char *s, char *delimiters)
    - returns a token on each subsequent call
    - on the first call function should be passes with string argument for 's'
    - on subsequent calls we should pass the string argument as NULL
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char s[100] = "Today is a rainy day";

    char *ptr = strtok(s, " ");
    // It creates a new array & then copy the first token & return the address of this array
    cout << ptr << endl;

    while(ptr!=NULL){
        // strtok() maintains a static variable that stores the state of the string
        ptr = strtok(NULL, " ");
        cout << ptr << endl;
    }
    return 0;
}

/* 
OUTPUT:

    Today
    is
    a
    rainy
    day
*/
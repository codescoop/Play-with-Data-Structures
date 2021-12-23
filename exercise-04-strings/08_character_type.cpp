/*
    Problem Name: Character Type

    Take the following as input:
    A character (ch) 
    Write a function that returns ‘U’, if it is uppercase; ‘L’ if it is lowercase and ‘I’ otherwise. 
    Print the value returned.

    Input Format: Character (ch)

    Constraints: No constraints

    Output Format: 'L' (if ch is lower-case) 'U' (if ch is upper-case) 'I' (otherwise)

    Sample Input: s

    Sample Output:  L

    Explanation: Anyone can Do it using Ascii codes. I dare you - "Try to not use ascii codes." ;).
*/

#include <iostream>
#include <string>
using namespace std;

// function to print character type
void getCharacterType(char ch)
{
    if(ch >= 'A' &&  ch <= 'Z'){
        cout << "U";
    }else if(ch >= 'a' &&  ch <= 'z'){
        cout << "L";
    }else{
        cout << "I";
    }
}

int main()
{
    char ch;
    cout << "Enter you character: ";
    cin >> ch;

    getCharacterType(ch);
    cout << endl;

    return 0;
}

/*
Approach:

    Problem statement is quite easy you just need to tell whether the character entered is Lower case or Uppercase otherwise print I.
    We can also compare characters directly without remembering the ascii codes.
    
Code:

    public static char tell(char ch) {

            if(ch >= 'a' && ch <= 'z')
                return 'L';
            else if(ch >= 'A' && ch <= 'Z')
                return 'U';
            else
                return 'I';

    }
*/
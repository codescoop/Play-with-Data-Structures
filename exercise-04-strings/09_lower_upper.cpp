/*
    Problem Name: Lower Upper

    Print "lowercase" if user enters a character between 'a-z' , 
    Print "UPPERCASE" is character lies between 'A-Z' and 
    print "Invalid" for all other characters like $,.^# etc.

    Input Format: Single Character

    Constraints: No constraints

    Output Format: lowercase UPPERCASE Invalid

    Sample Input: $

    Sample Output:  Invalid

    Explanation: NA
*/

#include <iostream>
#include <string>
using namespace std;

// function to print character type
void getCharacterType(char ch)
{
    if(ch >= 'A' &&  ch <= 'Z'){
        cout << "UPPERCASE";
    }else if(ch >= 'a' &&  ch <= 'z'){
        cout << "lowercase";
    }else{
        cout << "Invalid";
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
Algo
    1.Take Input of the character from the User.
    2.Chech if the character is in UpperCase ( if is between A - Z).
      Then, print UPPERCASE
    3.If the character is in LowerCase ( If character is in between a - z) .
      Print lowercase
    4.Otherwise, Print Invalid.
*/
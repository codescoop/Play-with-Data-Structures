/*
    Topic - String To Integer Recursion

    Given a string convert it into interger
    Eg:  Input  : "1234" 
         Output : 1234
*/

#include <iostream>
using namespace std;


// function to convert string to integer recursively
int strToInt(string s, int len)
{
    // base case
    if(len < 0)
    {
        return 0;
    }
    // rec case
    int digit = s[len] - '0';                 // Eg: '3' - '0' = 3
    int small_ans = strToInt(s, len-1);

    return (small_ans * 10) + (digit);        // Eg:  12*10 + 3 = 123
}


// function to drive code
int main()
{
    string s;
    cout << "Enter String: ";
    cin >> s;

    int result = strToInt(s, s.length()-1);
    
    cout << "String to Int: " << result;
    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter String: 1234
    String to Int: 1234

Case 2:
    Enter String: 15698
    String to Int: 15698
*/
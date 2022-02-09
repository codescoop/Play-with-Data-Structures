/*
    Topic - Replace Pi Recursion

    In a given a string, replace "pi" with "3.14" (inplace i.e without taking any extra space)
    Eg:  Input  : xpighpilmpipi
         Output : x3.14gh3.14lm3.143.14
*/

#include <iostream>
using namespace std;


// function to replace pi with 3.14
void replacePi(char c[], int idx)
{
    // base case
    if( c[idx] == '\0' or c[idx] == '\0')
    {
        return;
    }

    // rec case: Look for pi in current position
    if(c[idx] == 'p' and c[idx+1] == 'i')
    {
        // shifting + replacement with 3.14

        int j = idx+2;                     // pi = 2 charcater but 3.14 = 4 characters

        // take j to the end of the array (i.e until it points to NULL)
        while(c[j] != '\0')
        {
            j++;
        } 
        // shifting (right to left)
        while(j >= idx+2)
        {
            c[j+2] = c[j];
            j--;
        }
        // replacement with 3.14
        c[idx] = '3';
        c[idx+1] = '.';
        c[idx+2] = '1';
        c[idx+3] = '4';
        // recursive call on the remaining part
        replacePi(c, idx+4);
    }
    else{
        // go to next position
        replacePi(c, idx+1);
    }

    return;
}


// function to drive code
int main()
{
    char c[1000];
    cout << "Enter characters: ";
    cin >> c;

    replacePi(c, 0);

    cout << "After replacement: ";
    cout << c;

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter characters: abcpixyz
    After replacement: abc3.14xyz

Case 2:
    Enter characters: pistartpimidpiendpi
    After replacement: 3.14start3.14mid3.14end3.14

*/
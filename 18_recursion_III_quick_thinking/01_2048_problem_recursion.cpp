/*
    Topic - 2048 Problem Recursion

    Number to Spelling
      Input  : 2048 
      Output : two zero four eight
    
    APPRAOCH:
    - first make a recursive call (n/10)        (i.e n/10 reducing number)
    - then print spelling of last digit (n%10)  (i.e n%10 last digit)
*/

#include <iostream>
using namespace std;

// 2D character array of words as per index
char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};


void printSpellings(int num)
{
    // base case
    if(num == 0)
    {
        return;
    }
    // rec case
    printSpellings(num/10);
    // after the function call print spellings
    int last_digit = num%10;
    cout << words[last_digit] << " ";
    return;
}

// function to drive code
int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    cout << "Output: ";
    printSpellings(num);

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter number: 2048
    Output: two zero four eight

Case 2:
    Enter number: 189642
    Output: one eight nine six four two
*/
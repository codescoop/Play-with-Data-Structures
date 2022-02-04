/* 
    Topic - Increasing Decreasing Recursion

    Write 2 Functions to Print first N numbers in
    - Increasing
    - Descreasing


    Easiest Way to Approach to Recursive Problems
    "Magical" Recursive Rule = Principle of Mathematical Induction (PMI)
    1. Figure out the Base Case
    2. Assume Sub Problem can be solved by recursion (automatically)
    3. Using the sub-problem write the answer for the current problem.

*/

#include <iostream>
using namespace std;


void dec(int n)
{
    // base case
    if(n==0) 
    {
        return;
    }
    // recursive case
    cout << n << " ";     // Before function call, goes from Top to Base Case
    dec(n-1);
}


void inc(int n)
{
    // base case
    if(n==0) 
    {
        return;
    }
    // recursive case
    inc(n-1);
    cout << n << " ";    // After function call, goes in Bottom up direction (i.e from Base case towards Top)
}

// function to drive code
int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;

    cout << "Decreasing: ";
    dec(n);
    cout << "\nIncreasing: ";
    inc(n);
    
    cout << endl;
    return 0;
}

/* 
OUTPUT:
    Enter Number: 5
    Decreasing: 5 4 3 2 1
    Increasing: 1 2 3 4 5
 */
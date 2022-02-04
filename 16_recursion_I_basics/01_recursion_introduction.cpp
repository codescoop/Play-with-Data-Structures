/* 
    Topic - Recursion Introduction

    What is recursion ?
    - Recursion in Computer Science is a method where solution to a problem 
      depends on solution to smaller instances of same problem.
    - Using recursion we simplify the code for complex problems (eg: Tower of Hanoi)

    Parts of Recursive Algorithm
    1. Base Case
    2. Recursive Call (to work towards Base Case)


    Easiest Way to Approach to Recursive Problems
    "Magical" Recursive Rule = Principle of Mathematical Induction (PMI)
    1. Figure out the Base Case
    2. Assume Sub Problem can be solved by recursion (automatically)
    3. Using the sub-problem write the answer for the current problem.

    Example: Compute N!        [5! =  1*2*3*4*5 = 120]
*/

#include <iostream>
using namespace std;

// function to compute factorial of a given number (using recursion)
int fact(int n)
{
    // base case
    if(n==0)
    {
        return 1;
    }
    // recursive case
    return n * fact(n-1);
}

// function to drive code
int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;

    cout << "Factorial: ";
    cout << fact(n) << endl;
    
    return 0;
}

/* 
OUTPUT:

    Enter Number: 5
    Factorial: 120


Time Complexity:  O(N)  (Because we have made N calls & in each call we are doing constant operations 
                         i.e in recursive case multiplying two numbers O(1) & base case O(1))

Space Complexity: O(N)  (Because we are using implicit recursive stack & that is going to store 
                         'N' numbers of variables  i.e Having N numbers of stack frames & each 
                         stack frame contains constant number of variables)
 */
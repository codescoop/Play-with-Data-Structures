/* 
    Topic - Fibonacci Recursion | Call Stack Visualisation

    Problem: Nth Fibonacci using Recursion
             (0,1,1,2,5,8,13 ...... f(n).......)


    Easiest Way to Approach to Recursive Problems
    "Magical" Recursive Rule = Principle of Mathematical Induction (PMI)
    1. Figure out the Base Case
    2. Assume Sub Problem can be solved by recursion (automatically)
    3. Using the sub-problem write the answer for the current problem.

*/

#include <iostream>
using namespace std;

// function to compute Nth Fibonacci (using recursion)
int f(int n)
{
    // base case
    if(n==0 or n==1) 
    {
        return n;
    }
    // recursive case
    int f1 = f(n-1);
    int f2 = f(n-2);
    return f1 + f2;
}

// function to drive code
int main()
{
    int n;
    cout << "Enter Number: ";
    cin >> n;

    cout << "Fibonacci: ";
    cout << f(n) << endl;
    
    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter Number: 7
    Fibonacci: 13
    
Case 2:
    Enter Number: 4
    Fibonacci: 3



Call Stack Visualisation

    int f(int n)
    {                             Call Stack                          Recursion Tree
        // base case
        if(n==0 or n==1)                                                  4        
        {                          |________|                           /    \     
            return n;              |________|                          3      2    
        }                          |__n=1___|                         / \    / \   
        // recursive case          |__n=2___| f1=1  f2=0             2   1  1   0  
        int f1 = f(n-1);           |__n=3___| f1=1  f2=1            / \            
        int f2 = f(n-2);           |__n=4___| f1=2  f2=1           1   0           
        return f1 + f2;            |__main__| f=3                                 
    }
 */
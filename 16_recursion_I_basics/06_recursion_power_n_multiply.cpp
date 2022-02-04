/* 
    Topic - Time to Try Recursion!

    - Write a Recursive Functions to perform power(a,n)
    - Write a Recursive Functions to Multiply two numbers (a,b) without using * operator.
*/

#include <iostream>
using namespace std;

// functions to perform power(base,pow)
int power(int n, int p)
{
    // base case
    if(p == 0)
    {
        return 1;
    }
    // recursive case
    return n * power(n,p-1);
}


// functions to multiply two numbers (a,b) without using * operator
int multiply(int a, int b)
{
    // base case
    if(b==0)
    {
        return 0;
    }
    // recursive case
    return a + multiply(a, b-1);
}


// function to drive code
int main()
{
    int a,b;
    cout << "Enter Numbers [a & b]: ";
    cin >> a >> b;

    // compute power(base, pow)
    cout << "power(a,b): " << power(a,b) << endl;

    // muliply two number without using "*"
    cout << "multiply(a,b): " << multiply(a,b) << endl;

    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter Numbers [a & b]: 10 3
    power(a,b): 1000
    multiply(a,b): 30

Case 2:
    Enter Numbers [a & b]: 5 3
    power(a,b): 125
    multiply(a,b): 15

Case 3:
    Enter Numbers [a & b]: 2 4
    power(a,b): 16
    multiply(a,b): 8
 */
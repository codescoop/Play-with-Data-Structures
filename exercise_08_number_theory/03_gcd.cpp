/*
    Problem: GCD

    Take the following as input.
    A number (N1)
    A number (N2)
    Write a function which returns the GCD of N1 and N2. Print the value returned.

    Input Format: Two integers seperated by a new line.

    Constraints:  0 < N1 < 1000000000
                  0 < N2 < 1000000000

    Output Format: Output a single integer which is the GCD of the given integers.

    Sample Input:  16 
                   24

    Sample Output:  8

    Explanation: The largest number that divides both N1 and N2 is called the GCD of N1 and N2.

*/


#include <iostream>
using namespace std;

// function to find greatest common factor (using Euclidean algorithm)
int gcd(int a, int b)
{
    return a == 0 ? b : gcd(b%a,a);
}

// functon to drive code
int main()
{
    int a,b;
    cout << "Enter Numbers [a & b]: ";
    cin >> a >> b;

    cout << "GCD : ";
    cout << gcd(a,b) << endl;

    return 0;
}


/* 
OUTPUT:

Case 1:
    Enter position: 1
    Prime No: 2

Case 2:
    Enter position: 9865
    Prime No: 103123

Case 3:
    Enter position: 456
    Prime No: 3221




APPROACH 1: (Using Euclidean algorithm)

    The algorithm is based on below facts:
    - If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change.
    - So if we keep subtracting repeatedly the larger of two, we end up with GCD.
    - Now instead of subtraction, if we divide smaller number, the algorithm stops when we find remainder 0.

CODE:

    int gcd(int a,int b)
    {
        return b==0 ? a : gcd(b,a%b);
    }


APPROACH 2: (Using Long Division Method)

    Finding highest common factor (H.C.F) by prime factorization for large number is not very convenient. 
    The method of long division is more useful for large numbers.

    We use the repeated division method for finding highest common factor (H.C.F) of two or more numbers. 
    To find highest common factor by using division method we follow these steps: 
    Step I   : Divide the large number by the smaller one.
    Step II  : Then the remainder is treated as divisor and the divisor as dividend.
    Step III : Divide the first divisor by the first remainder.
    Step IV  : Divide the second divisor by the second remainder.
    Step V   : Continue this process till the remainder becomes 0.
    Step VI  : The divisor which does not leave a remainder is the H.C.F. or G.C.D. of the two numbers and
               thus, the last divisor is the required highest common factor (H.C.F) of the given numbers.

    Let us consider some of the examples to find highest common factor (H.C.F) by using division method.
                  ___1__
    step 1:    18|  30  
                  _-18_ ___1__
    step 2:         12 |  18             -> Dividing the first divisor by the first remainder
                        _-12_ ___2__
    step 3:                6 |  12       -> Dividing the second divisor by the second remainder
                              _-12__
                                0        -> Remainder is 0  & HCF = 6


Code

    public static int gcd(int dividend, int divisor)
    {
        while(dividend % divisor != 0)
        {
            int rem = dividend % divisor;
            dividend = divisor;
            divisor = rem;
        }
        return divisor;
    }

*/
/*
    Problem Name - Count Set Bits

    count number of 1s in binary representation of an integer

    Input Format:  Input N = Number of Test Cases, followed by N numbers

    Output Format: Number of Set Bits in each number each in a new line

    Sample Input:   3
                    5
                    4
                    15

    Sample Output:  2
                    1
                    4

    Explanation:  Convert Binary to Decimal first and then count number of 1's present in all digits.
*/


#include <iostream>
using namespace std;

// function to count set bits
int coutSetBits(int n)
{
    int count = 0;
    while(n)
    {
        n = n & (n-1);        // removing the last set bits
        count++;              // count is the no. of times loop run
    }
    return count;
}


// function to drive code
int main()
{
    int testcase, num;
    
    cout << "Enter total testcases: ";
    cin >> testcase;

    while(testcase--)
    {
        cout << "Enter Number: ";
        cin >> num;

        cout << "Total Set Bits: ";
        cout << coutSetBits(num) << endl;
    }

    return 0;
}

/* 

OUTPUT:

    Enter total testcases: 3

    Enter Number: 5
    Total Set Bits: 2

    Enter Number: 4
    Total Set Bits: 1

    Enter Number: 15
    Total Set Bits: 4


APPROACH:

    With bitwise operations, we can use an algorithm whose running time depends on the 
    number of ones present in the binary form of the given number.

        int count_set_nits (int n)
        {
            while( n > 0)
            {
            n = n&(n-1);
            count++;
            }
            return count;
        }
    
    How does this algorithm work? 
    
    We can observe that there is a relationship between a number N and N-1. 
    N-1 will have all the bits same as x except for the rightmost 1 in x and all the bits to 
    the right of rightmost 1 in x. 
    So as in x-1, the rightmost 1 and bits right to it is flipped, then by performing x&(x-1), 
    and storing it in x, will reduce x to a number containing number of ones(in its binary form) 
    less than the previous state of x, thus increasing the value of count in each iteration. 
    This is also known as Brian Kernighan Algorithm.
*/
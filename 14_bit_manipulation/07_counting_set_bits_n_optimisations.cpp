/*
    Topic: Counting Set Bits & Optimisations

    - Given a Number N, find number of set bits in binary representation of it.
    
      Eg: Input : 13 (1101)
          Output: 3
*/


#include <iostream>
using namespace std;


// function to count set bits
int countBits(int n)
{
    int count = 0;
    while(n)
    {
        count += (n&1);
        n = n>>1;
    }
    return count;
}

// approach 2
int countBitsFast(int n)
{
    int count = 0;
    while(n)
    {
        n = n & (n-1);     // removing the last set bits
        count++;           // count is the no. of times loop run
    }
    return count;

    /*
       Eg:  when n   = 5             0101
                 n-1 = 4           & 0100
                                   -------
                 n & (n-1) = 4       0100

            when n   = 4             0100
                 n-1 = 3           & 0011
                                   -------
                 n & (n-1) = 0       0000
            
            Time Complexity: O(No. of Set Bits)
    */
}

// function to drive code
int main()
{
    int n;

    cout << "Enter numbers: ";
    cin >> n;

    cout << "count: " << countBits(n) << endl;                 // Approach 1
    cout << "count: " << countBitsFast(n) << endl;             // Approach 2
    cout << "count: " << __builtin_popcount(n) << endl;        // Buildin Method

    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter numbers: 5
    count: 2

Case 2:
    Enter numbers: 13
    count: 3

*/
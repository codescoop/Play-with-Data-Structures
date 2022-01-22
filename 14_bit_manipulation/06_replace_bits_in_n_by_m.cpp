/*
    Topic: Replace Bits in N by M

    You are given two 32-bits numbers, N and M, and two bit positions. i and j.
    Write a method to set all bits between i and j in N equal to M
    (e.g., M becomes a substring of N located at i and starting at j)

    Eg: Input: N = 1024 (10000000000)
               M = 21   (10101) 
               i = 2
               j = 6
        Output N = 1108 (10001010100)
*/

#include <iostream>
using namespace std;


// function to update i-th bit of a given number
int clearRangeItoJ(int n, int i, int j)
{
    int ones = -1;
    int first_half = ones << (j+1);
    int second_half = (1<<i)-1;            // pow(2,i)-1
    int mask = first_half | second_half;
    int ans = n & mask;
    return ans;
}

// function to replace bits in N by M
int replaceBits(int n, int m, int i, int j)
{
  int cleared_n = clearRangeItoJ(n, i ,j);
  int mask = m << i;
  int ans = cleared_n | mask;
  return ans;
}

// function to drive code
int main()
{
    int n,m,i,j;

    cout << "Enter numbers [N & M]: ";
    cin >> n >> m;

    cout << "Enter bit positions [i & j]: ";
    cin >> i >> j;

    cout << "Number after replacing : ";
    cout << replaceBits(n, m, i, j);

    cout << endl;
    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter numbers [N & M]       : 1024 21
    Enter bit positions [i & j] : 2 6
    Number after replacing      : 1108

Case 2:
    Enter numbers [N & M]       : 15 2
    Enter bit positions [i & j] : 1 3
    Number after replacing      : 5

Approach:

  - clear bits of N from range i to j
  - create a mask from m 
    (i.e left shift m by i bits)
  - return bitwise OR of cleared_N & mask

*/
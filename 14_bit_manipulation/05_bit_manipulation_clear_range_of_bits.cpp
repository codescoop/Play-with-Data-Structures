/*
    Topic: Bit Manipulation - Clear Range of Bits

    - Clearing last n bits
    - Clearing bits between i to j
*/

#include <iostream>
using namespace std;


// function to clear last n bits
int clearLastBit(int n, int i)
{
    int ones = ~(0);
    int mask =  ones << i;
    int ans = (n & mask);
    return ans;

    /* 
        Approach:
        - create the required mask: left shift i-bits from all ones (i.e ~(0) or -1)
        - return bitwise AND of number & mask. 
        
        Eg:   n = 31  (00011111)
              i = 3

              mask = 11111000             (i.e ~(00000000) << 3) => (11111111 << 3) => 11111000) 

                00011111     (n=31)
              & 11111000     (mask)
              -----------
                00011000   (Output=24)
    */
}


// function to clear bits between range i to j
int clearRangeItoJ(int n, int i, int j)
{
    int ones = -1;
    int first_half = ones << (j+1);
    int second_half = (1<<i)-1;            // pow(2,i)-1
    int mask = first_half | second_half;
    int ans = n & mask;
    return ans;

    /* 
        Approach
        - Create the first & second parts of mask
            a. first half (all ones after j): left shift j+1 bits from all ones
            b. second half (all ones upto i):  pow(2,i)-1     (Eg:1,3,7,15...)
        - creating the mask : bitwise OR of first & second part of mask
        - return Bitwise AND of number & mask
   
        Eg:   n = 31  (00011111)
              i = 1
              j = 3

              first_half  =  11110000      (i.e -1 << (3+1))  => (11111111 << 4) => 11110000)  
              second_half =  00000001      (i.e pow(2,i) - 1) => (1 << i) - 1    => 00000001 )
              mask        =  11110001      (i.e 11110000 | 00000001) 

                00011111      (n=31)
              & 11110001      (mask)
              ------------
                00010001    (Output=17)
    */
}


// function to drive code
int main()
{
    int n,i,j;

    cout << "Enter number: ";
    cin >> n;

    // Clearing last n bits
    cout << "How many last bits do you want to clear: ";
    cin >> i;

    cout << "Number "<< n << " after clearing last " << i << "-bits : " << clearLastBit(n,i) << "\n\n";
    

    // Clearing bits between i to j
    cout << "Enter Range [i & j]: ";
    cin >> i >> j;

    cout << "Number "<< n << " after clearing bits from " << i << " to " << j << " : " << clearRangeItoJ(n,i,j);

    cout << endl;
    return 0;
}

/* 
OUTPUT:

  Enter number: 31

  How many last bits do you want to clear: 3
  Number 31 after clearing last 3-bits : 24

  Enter Range [i & j]: 1 3
  Number 31 after clearing bits from 1 to 3 : 17

*/
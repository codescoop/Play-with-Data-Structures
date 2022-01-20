/*
    Topic: Bit Manipulation - Get & Set Bits

    Common Bit Tasks
    - Check if given n is odd/even.
    - Get/find i-th bit (from right)
    - Set the i-th bit
*/

#include <iostream>
using namespace std;

// function to check odd & even using Bitwise AND Operator
int isOdd(int n)
{
    /*  
        Bitwise AND of n and 1 will
        return 1 if number is odd 
               0 if number is even
        
        Eg:   5 =  0101        4 =  0100
                 & 0001           & 0001
                 --------          -------
                   0001             0000
    */
    return (n & 1);
}


// function to find i-th bit of a given number
int getBit(int n, int i)
{
    int mask = (1 << i);          // mask = Left shift i bits
    int bit = (n & mask) > 0 ? 1 : 0;
    /* 
        Bitwise AND of n and mask will, 
        return   0    if number is 
                >0    if number is 
   
        Eg:   n = 5 (0101)
              i = 2
              mask = 0100   (i.e 0001 << 2) 

                   0101      (5)
                 & 0100    (mask)
                 --------  
                   0100    (greater than 0)
        
        So, the i-th bit is 1, when return value is >0
                            0, when return value is 0
    */
    return bit;
}


// function to set i-th bit of a given number
int setBit(int n, int i)
{
    int mask = (1 << i);         // mask = Left shift i bits
    int ans = (n | mask);
    /* 
        Bitwise OR of n and mask will, 
   
        Eg:   n = 5  (0101)
              i = 3
              mask = 1000  (i.e 0001 << 3) 

                0101      (5)
              | 1000    (mask)
              --------  
                1101     (13)
    */
    return ans;
}


// function to drive code
int main()
{
    int n, i;

    // check if given n is odd or even.
    cout << "Check Even/Odd (Enter number): ";
    cin >> n;

    if(isOdd(     n))
        cout << n << " is Odd " << endl;
    else
        cout << n << " is Even " << endl;


    // Finding the i-th bit (from right)
    cout << "Get Bit (Enter the i-th bit you want to get): ";
    cin >> i;

    cout << i << "th-bit of number " << n << " is: " << getBit(n,i) << endl;


    // Set the i-th bit
    cout << "Set Bit (Enter the i-th bit you want to set): ";
    cin >> i;

    cout << "number " << n << " after setting " << i <<"th-bit is: " << setBit(n,i);

    cout << endl;
    return 0;
}

/* 
OUTPUT:

    Check Even/Odd (Enter number): 7
    7 is Odd 

    Get Bit (Enter the i-th bit you want to get): 5
    5th-bit of number 7 is: 0

    Set Bit (Enter the i-th bit you want to set): 6
    number 7 after setting 6th-bit is: 71

*/
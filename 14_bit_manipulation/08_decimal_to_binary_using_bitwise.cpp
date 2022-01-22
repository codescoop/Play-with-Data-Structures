/*
    Topic: Decimal to Binary using Bitwise

    - Given a Number N, convert number into its binary representation.
    
      Eg: Input : 13
          Output: 1101
*/


#include <iostream>
using namespace std;


// function to convert decimal into binary
int decimalToBinary(int n)
{
    int binary_n = 0;
    int pow = 1;
    while(n)
    {
        int last_bit = n&1;
        binary_n += pow*last_bit;
        n = n>>1;
        pow *= 10;
    }
    return binary_n;
}


// function to drive code
int main()
{
    int n;

    cout << "Enter numbers: ";
    cin >> n;

    cout << n << " = " << decimalToBinary(n) << endl;

    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter numbers: 9
    9 = 1001

Case 2:
    Enter numbers: 13
    13 = 1101

*/
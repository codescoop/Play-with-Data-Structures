/*
    Topic: Fast Exponentiation using Bitmasking

    - Exponentiation/Power using Bitmasking

      Eg: Input : n=2
                  p=6
          Output: 64

*/


#include <iostream>
using namespace std;

// Exponentiation/Power using Bitmasking
int power_optimised(int num, int power)
{
    int ans = 1;
    while(power)
    {
        int last_bit = power&1;
        if(last_bit == 1)
        {
            ans = ans*num;
        }
        num = num*num;        // Square up
        power = power>>1;     // Discard the last bit
    }
    return ans;

    /* 
        Approach:
        
        - Iterate over each binary value of 'power' & perform the below operations:
        1. Multiply 'n' by its current value
        2. if  extracted_bit = 1   => multiply result-value by n (i.e current value of n)
               extracted_bit = 0   => skip


        Eg: when  n = 3
                  p = 5 (101)
    
        Current value of n (for each binary value of p) :  n=81   n=9   n=3 
                                                            1      0     1
                                               Output   =  81 * (skip) * 3
                                                        =  243
    */
}

// function to drive code
int main()
{
    int num, power;

    cout << "Enter [Number & Power]: ";
    cin >> num >> power;


    cout << "Output: " << power_optimised(num, power);
    cout << endl;

    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter [Number & Power]: 5 2
    Output: 25

Case 2:
    Enter [Number & Power]: 2 10
    Output: 1024

Case 3:
    Enter [Number & Power]: 3 5
    Output: 243
*/
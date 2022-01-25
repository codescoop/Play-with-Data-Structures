/*
    Problem Name - XOR Profit Problem

    We are given two coins of value x and y. We have to find the maximum of value of a XOR b
    where x <= a <= b <= y.

    Input Format: We are given two integers x and y

    Constraints:  l <= r <= 1000

    Output Format: Print the maximum value of a XOR b

    Sample Input:  5
                   6

    Sample Output: 3

    Explanation: If a and b are taken to be 5. Then a xor b = 0
                 If a and b are taken to be 6. Then a xor b = 0
                 If a is 5 and b is 6. Then a xor b is 3.
*/

#include <iostream>
using namespace std;

/*
    function to find maximum xor value between range x & y
    Approach 1: A brute force solution is to generate all pairs. find their XOR values and finally return
    the maximum XOR value
*/
int max_xor_value(int x, int y)
{
    int result = 0;
    for (int i = x; i <= y; i++)
    {
        for (int j = x + 1; j <= y; j++)
        {
            result = max(i ^ j, result);
        }
    }
    return result;
}

// Approach 2: A efficient solution is to consider pattern of binary values from L to R.
int max_xor_value_optimised(int l, int r)
{
    // find xor of l & r   (it will be of form 1xxxx... ,where x can be 0 or 1)
    int num = l^r;  

    // find the position of msb(most significant bit) of l^r (i.e 1xxxx...)
    int pos = 0;
    while (num)
    {
        num = num >> 1;
        pos++;
    }

    // Now, max XOR val will of form 11111...  i.e (2^pos -1)
    int result = (1<<pos) - 1;
    return result;

    /*  Eg: when  num  = 1xxx          (x can be 0 or 1)
                  pos  = 4
                              pos
                               |                   pos
                  max number = 1111   = 15   i.e (2  - 1) 
    */
}

// function to drive code
int main()
{
    int x, y;

    cout << "Enter Coin values: ";
    cin >> x >> y;

    cout << "Max XOR Value: ";
    // cout << max_xor_value(x,y);               // Approach 1 (Brute Force)
    cout << max_xor_value_optimised(x, y); // Approach 2 (considering pattern of binary values)

    cout << endl;
    return 0;
}

/*

OUTPUT:

Case 1:
    Enter Coin values: 5 6
    Max XOR Value: 3

Case 2:
    Enter Coin values: 5 10
    Max XOR Value: 15


APPROACH:

    - Brute Force Approach
      A simple solution is to generate all pairs, find their XOR values and finally return the
      maximum XOR value.

    - Optimised Approach
      An efficient solution is to consider pattern of binary values from L to R.

      We can see that first bit from L to R either changes from 0 to 1 or it stays 1
      i.e. if we take the XOR of any two numbers for maximum value their first bit will be fixed which
      will be same as first bit of XOR of L and R itself.

      After observing the technique to get first bit, we can see that if we XOR L and R,
      the most significant bit of this XOR will tell us the maximum value we can achieve
      i.e. let XOR of L and R is 1xxx where x can be 0 or 1 then maximum XOR value we can get is 1111
      because from L to R we have all possible combination of xxx and it is always possible to choose
      these bits in such a way from two numbers such that their XOR becomes all 1.

Ref -  https://www.youtube.com/watch?v=wFuMDWF3ewc

*/
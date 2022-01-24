/*
    Problem Name: Power(O(logn))

    Take as input x and n, two numbers. Write a function to calculate x raise to power n. 
    Target complexity is O(logn). 
    NOTE: Try both recursive and bitmasking approach.

    Input Format: Enter the number N and its power P

    Constraints:  None

    Output Format: Display N^P

    Sample Input:  2
                   3

    Sample Output: 8
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



APPROACH: (recursive)

    Using divide and conquer technique we can observe the following recurrence
    power(x, n) = power(x, n / 2) * power(x, n / 2);        // else n is even
    power(x, n) = x * power(x, n / 2) * power(x, n / 2);    // if n is odd


Code: (Using recursive approach)

    #include<iostream>
    using namespace std;

    float power(float x, int y)
    {
        float temp;

        if( y == 0)
            return 1;

        temp = power(x, y/2);

        if (y%2 == 0)
            return temp*temp;
        else
        {
            if(y > 0)
                return x*temp*temp;
            else
                return (temp*temp)/x;
        }
    }  

    int main() 
    {
        int num, pw;
        cin >> num >> pw;
    
        cout << power(num,pw);
    
        return 0;
    }
*/
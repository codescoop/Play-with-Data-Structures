/*
    Problem: Modular Exponentiation (Power in Modular Arithmetic))

    Given three numbers a,b,c. Calculate (a^b)mod c.

    Input Format: Single line containing three integers a,b,c separated by space.

    Constraints:  1<=a,b,c<=100000

    Output Format: Print (a^b)mod c.

    Sample Input: 2 2 3
                  2312 3434 6789
                  -3 5 89

    Sample Output: 1
                   6343
                   -65

    Explanation: (2^2)mod3  = 4mod3 = 1
*/


#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

// function to compute modular power (Recursive)
int exponentMod1(ll a, ll b, ll c)
{
    // Base cases
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;

    ll power;
    ll y;

    power = exponentMod1(a, b/2, c);
    /* Note: when b = 4  =>  b/2 = 2       // Even Case
             when b = 5  =>  b/2 = 2       // Odd Case
     */
    
    // if b is odd
    if(b&1)
    {
        y = (a * power * power)%c;
    }
    // if b is even
    else
    {
        y = (power * power)%c;
    }

    // return (int)y%c;
    return (int)((y+c)% c);          // to handle mod of a negative number
}


// function to compute modular power (Recursive)
int exponentMod(ll a, ll b, ll c)
{
    // Base cases
    if (a == 0)
        return 0;
    if (b == 0)
        return 1;

    ll power;
    ll y;
    // if b is odd
    if(b&1)
    {
        power = exponentMod(a, b-1, c);
        y = (a * power)%c;
    }
    // if b is even
    else
    {
        power = exponentMod(a, b/2, c);
        y = (power * power)%c;
    }

    // return (int)y%c;
    return (int)((y+c)% c);          // to handle mod of a negative number
}


// function to compute modular power (Iterative)
int exponentModIterative(ll a, ll b, ll c)
{
    ll res = 1;

    // Update 'x`' if it is more than or equal to 'c' 
    a = a%c;
    
    // In case 'a' is divisible by 'c'
    if(a==0)
    {
        return 0;
    }

    while(b)
    {
        // If b is odd, multiply 'a' with result
        if(b&1)
        {
            res = (res*a)%c;
        }
    
        // b = b/2;
        b = b>>1;

        // change x to x^2
        a = (a*a)%c;
    }
    return (int)res;
}

// function to drive code
int main()
{
    ll a,b,c;
    cout << "Enter Numbers [a,b & c]: ";
    cin >> a >> b >> c;

    // ll power = pow(a,b);           // Naive Approach : It will cause overflow when storing large number
    // cout << power%c << endl;

    // int ansRec = exponentMod1(a,b,c);               // Recursive Approach
    int ansItr = exponentModIterative(a,b,c);         // Iterative Approach

    cout << "(a^b)mod c : ";
    // cout << ansRec << endl;
    cout << ansItr << endl;

    return 0;
}


/* 
OUTPUT:

Case 1:
    Enter Numbers [a,b & c]: 2 2 3
    (a^b)mod c : 1

Case 2:
    Enter Numbers [a,b & c]: 2312 3434 6789
    (a^b)mod c : 6343
    
Case 3:
    Enter Numbers [a,b & c]: -3 5 89
    (a^b)mod c : -65


APPROACH:
    
    Given three numbers a, b and c, we need to find (a^b) % c
    Now why do “% c” after exponentiation, because ab will be really large even for relatively small values
    of a, b and that is a problem because the data type of the language that we try to code the problem, 
    will most probably not let us store such a large number.

    Solution:  The idea is based on below properties.
   
    Property 1: The Divide & Conquer approach squares the number each time, rather than multiplying it
                with the number itself.

                if b is even: 
                    (a ^ b) mod c = ((a ^ b/2) * (a ^ b/2)) mod c     ? this suggests divide and conquer 
                if b is odd: 
                    (a ^ b) mod c = (a * (a^(b-1)) mod c

    Property 2: Use Modular Multiplication rule on above expression
                (a * b)mod c = ((a mod c) * (b mod c))mod c

    Property 3: If we have to return the mod of a Negative Number 'x' whose Absolute Value is less than 'y': 
                then (x + y)mod y will do the trick
    
    Note:  Also as the product of (a ^ b/2) * (a ^ b/2) and a * (a ^( b-1)) may cause overflow, 
           hence we must be careful about those scenarios 

    We just need to modify the logarithmic power function to handle overflow using modulo arithmetic.
*/
/*
    Topic: Inclusion Exclusion Concept + Implementation

    Problem: Not So Easy Math

    After the release of Avengers, Ironman and Thor got into fight and ironman challenged Thor to
    find out number of numbers between 1 and n which are divisible by any of the prime number less
    than 20.

    Sample Input:  t:  5
                   n:  5
                      10 
                      12 
                      15 
                      18
    
    Sample Output: 4
                   9
                   11
                   14
                   17

*/


#include <iostream>
using namespace std;

#define ll long long


// function to drive code
int main()
{
    // list of primes less than 20
    ll primes[] = {2,3,5,7,11,13,17,19};


    ll t;
    cout << "Enter testcases: ";
    cin >> t;

    while(t--)
    {
        int n;
        cout << "Enter Number: ";
        cin >> n;

        // as there are 8 primes less than 20. So total subset = (2^8)-1 = 255
        ll total_subsets = (1<<8)-1;         // 2^N-1    NOTE: -1 for not including value=0 (i.e NULL subset)
        ll ans = 0;

        for(ll num=1; num<=total_subsets; num++)
        {
            ll denominator = 1ll;
            // count number of set bits
            ll setBits = __builtin_popcount(num);
                 
            // iterate over all bits positions
            for(ll pos=0; pos<=7; pos++)
            {
                if(num & (1<<pos))
                {
                    denominator = denominator*primes[pos];
                }
            }

            // if setbit is odd
            if(setBits&1)
            {
                // Add for odd case 
                ans +=  n/denominator;
            }
            else
            {
                // Subtract for even case
                ans -= n/denominator; 
            }
        }

        cout << "Total numbers divisible by prime <20: ";
        cout << ans << endl;
    }
    return 0;
}

/* 

OUTPUT:
    Enter testcases: 5

    Enter Number: 5
    Total numbers divisible by prime <20: 4

    Enter Number: 10
    Total numbers divisible by prime <20: 9

    Enter Number: 12
    Total numbers divisible by prime <20: 11

    Enter Number: 15
    Total numbers divisible by prime <20: 14

    Enter Number: 18
    Total numbers divisible by prime <20: 17


Concept:

    Formula for the union of these sets is as follows:

    1. |A∪B|     = |A| + |B| - |A∩B|
                   Odd          Even

    2. |A∪B∪C|   = |A| + |B| + |C| - |A∩B| - |B∩C| - |C∩A| + |A∩B∩C| 
                   Odd                Even                     Odd

    3. |A∪B∪C∪D| = |A| + |B| + |C| + |D| - |A∩B| - |B∩C| - |C∩D| ...... + |A∩B∩C| + |A∩B∩D| ..... - |A∩B∩C∩D|
                   Odd                      Even                            Odd                       Even
    
    4. |A∪B∪C∪D∪E| =  |A| ........ 
    
    .
    .
    .

    If we observe the General Overall Pattern:

    - Add for ODD elements in set
    - Subtract for EVEN elements in set


    Problem: How many numbers are there which are less than 1000 (< 1000) & they are divisible by 2, 3 & 5.
    
    Solution: Range is from 1 to 999
              
              S |2| =    999/2       = 499             // lower bound value
              S |3| =    999/3       = 333
              S |5| =    999/5       = 199
              |2∩3| =    999/(2*3)   = 999/6   = 166
              |3∩5| =    999/(3*5)   = 999/15  = 66
              |5∩2| =    999/(5*2)   = 999/10  = 99
            |2∩3∩5| =    999/(2*3*5) = 999/30  = 33
             
             |2∪3∪5|   = |2| + |3| + |5| - |2∩3| - |3∩5| - |5∩2| + |2∩3∩5| 
                       = 499 + 333 + 199 - 166 - 66 -99 + 33
                       = 733

            So, there are 733 intergers upto 1000 which has 2,3 & 5 as divisor

    Explaination: 
    
    N   = 1000
    arr = {2,3,5}      <N

    So,to solve this problem follow the below steps:
    1. Generate all Subsets of this set. (use bitmasking)
    2. Then, if subset has Odd number of elements that we will ADD the answer for it &
             if subset has Even number of elements that we will SUBTRACT the answer for it

          ABC        (A=2 B=3 C=5)
    1     001    C     5
    2     010    B     3
    3     011   BC    35
    4     100    A     5
    .       .    .     .
    .       .    .     .
    .       .    .     .
    2^N-1   .    .     .
    
    So, extracts the bits & take product of these numbers & compute N/product of numbers
*/
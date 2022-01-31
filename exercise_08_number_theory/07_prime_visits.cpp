/*
    Topic: Prime Visits (Prime Sieve Problem)
    
    PMO gives two random numbers a & b to the Prime Minister. PM Modi wants to visit all countries 
    between a and b (inclusive) , However due to shortage of time he can't visit each and every
    country, So PM Modi decides to visit only those countries,for which country number has two divisors.
    So your task is to find number of countries Mr. Modi will visit.

    Input Format: The first line contains N , no of test cases. 
                  The next N lines contain two integers a and b denoting the range of country numbers.

    Constraints: a<=1000000 & b<=1000000.
                 N<=1000

    Output Format: Output contains N lines each containing an answer for the test case.

    Sample Input:   2
                    1 10
                    11 20

    Sample Output:  4
                    4

    Explanation: PM Modi chooses countries with numbers 2,3,5 and 7 for the first testcase.
                 For the second testcase , he chooses countries with numbers 11,13,17 and 19.
*/


#include <iostream>
#include <bitset>
using namespace std;

#define ll long long

int const SIZE = 10000007;
bitset<SIZE> p;
int csum[SIZE] = {0};

// funcction to get all primes using Seive of Eratosthenes
void prime_sieve()
{   
    // set all bits
    p.set();

    // 0 & 1 are not prime
    p[0] = p[1] = 0;

    for(ll i=2; i<=SIZE; i++)
    {
        if(p[i]==1)
        {
            // set all multiples of i as Not Prime
            for(ll j=i*i; j<=SIZE; j=j+i)
            {
                p[j] = 0;
            }
        }
    }
}


// functon to drive code
int main()
{
    // get all primes & updating cumulative sum
    prime_sieve();

    // cumulative sum for count of prime values
    for(ll i=1; i<=SIZE; i++)
    {
        csum[i] = csum[i-1] + p[i];
    }

    int t;
    cout << "Enter total testcases: ";
    cin >> t;

    while(t--)
    {
        int a, b;
        cout << "Enter numbers [a & b]: ";
        cin >> a >> b;

        int res = csum[b] - csum[a-1];

        cout << "Total Countries : ";
        cout << res << endl;
    }

    return 0;
}


/* 
OUTPUT:
    Enter total testcases: 3

    Enter numbers [a & b]: 1 10
    Total Countries : 4

    Enter numbers [a & b]: 11 20
    Total Countries : 4

    Enter numbers [a & b]: 589 96874
    Total Countries : 9219


APPROACH:
    The above problem is to generate all primes number between a and b.

*/
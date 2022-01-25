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
using namespace std;

#define MAX_LIMIT 1000000          // As a,b<=1000000
#define ll long long

// Prime Sieve & Optimisations
void prime_sieve(int *p, int n)
{
    // special cases
    p[0] = p[1] = 0;
    p[2] = 1;

    // Let us mark all odd number's as Prime (Initialisation)
    for(ll i=3;i<=n; i+=2)
    {
        p[i]=1;
    }

    // Sieve Login to mark non prime numbers as 0
    // 1. Optimisation: Iterate over odd numbers
    for(ll i=3; i<=n; i+=2)
    {
        // check if the current number (at index-i) is marked (i.e it is prime)
        if(p[i]==1)
        {
            // Mark all the multiples of that number as not prime
            // 2. Optimisation: Starting from i*i instead of 2*i
            for(ll j=i*i; j<=n; j=j+i)
            {
                p[j] = 0;
            }
        }
    }
}


// function to drive code
int main()
{
    // precompute the primes upto MAX_LIMIT
    int p[MAX_LIMIT] = {0};        // to store bool status for primes values
    prime_sieve(p, MAX_LIMIT);
    
    // cumulative sum of number of the primes upto MAX_LIMIT
    int csum[MAX_LIMIT] = {0};
    for(ll i=1; i<=MAX_LIMIT; i++)
    {
        csum[i] = csum[i-1]+p[i];
    }

    int q;
    cout << "Enter total queries: ";
    cin >> q;
    
    while(q--)
    {
        int a,b;
        cout << "Enter number [a & b]: ";
        cin >> a >> b;

        int result = csum[b] - csum[a-1];
        cout << "Output: " << result << endl;
    }

    return 0;
}

/* 
OUTPUT:
    Enter total queries: 2

    Enter number [a & b]: 1 10
    Output: 4

    Enter number [a & b]: 11 20
    Output: 4

*/
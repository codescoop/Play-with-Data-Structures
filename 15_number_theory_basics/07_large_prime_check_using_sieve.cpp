/*
    Topic: Large Prime Check (using sieve)

    - Space Optimised Sieve using Bitset 
    - Given a number n. Check if number n is prime or Not (~ 10^12)
      Eg:   n  : 2147483647          (i.e 10 digit prime number)
            Output : Yes
        
            n  : 799980626860
            Output : No

    NOTE:
      - As, sieve has a limitation to calculate prime upto 10000000 (i.e 10^7)
      - So, if a number is greater than 10^7 then we should use different approch.


    Problems with Simple Sieve:

    The Sieve of Eratosthenes looks good, but consider the situation when n is large, the Simple Sieve 
    faces the following issues.
    - An array of size Θ(n) may not fit in memory
    - The simple Sieve is not cached friendly even for slightly bigger n. The algorithm traverses the
      array without locality of reference
*/

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define ll long long


int const n = 10000000;          // 10^7
bitset<n> b;
vector<ll> primes; 


// Space Optimised Sieve using Bitset 
void sieve()
{
    // set all bits
    b.set();            //1,1,1,1,1 ....

    // 0 & 1 are not prime
    b[0] = b[1] = 0;

    for(ll i=2; i<=n; i++)
    {
        if(b[i])
        {
            primes.push_back(i);              // store all prime numbers
            for(ll j=i*i; j<=n; j=j+i)
            {
                b[j] = 0;
            }
        }
    }
}


// function to check prime number
bool isPrime(ll num)
{
    // Case: if number is less than 10^7
    if(num<=n)
    {
        return b[num]==1 ? true : false;
    }
    
    // Case: if number greater than 10^7 (upto ~10^12)
    // loop upto sqrt(N)
    for(ll i=0; primes[i]*(ll)primes[i] <= num; i++)
    {
        if(num%primes[i] == 0)
        {
            return false;
        }
    }

    return true;
}


// function to drive code
int main()
{
    // get prime number using sieve
    sieve();

    int t;
    cout << "Enter testcases: ";
    cin >> t;

    while(t--)
    {
        ll num;
        cout << "Enter a positive integer: ";
        cin >> num;

        // check for prime nunber
        bool status = isPrime(num);

        if(status) {
            cout << num << " is a prime number";
        }
        else{
            cout << num << " is not a prime number";
        }
        cout << endl;
    }

    return 0;
}

/* 
OUTPUT:
    Enter testcases: 3

    Enter a positive integer: 2147483647
    2147483647 is a prime number

    Enter a positive integer: 799980626860
    799980626860 is not a prime number

    Enter a positive integer: 999998999999 
    999998999999 is a prime number
 */
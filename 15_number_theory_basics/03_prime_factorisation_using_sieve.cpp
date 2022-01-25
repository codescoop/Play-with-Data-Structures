/*
    Topic: Prime Factorisation (using Sieve)

    - Prime Factorisation of a Number
      1. Natve Approach        (check prime for 2 to N)
      2. Optimized Approach    (check prime for 2 to sqrt(N))
      3. Sieve Based Approach  (It is useful when we have many queries & we have to compute prime factors 
                                for every number. So, its better to create a prime sieve that will store
                                all the the primes numbers i.e precompute the prime )

*/

#include <iostream>
#include <vector>
using namespace std;

#define ll long long

// Prime Sieve & Optimisations
vector<int> primeSieve(int *p, int n)
{
    // special cases
    p[0] = p[1] = 0;
    p[2] = 1;

    // Let us mark all odd number's as Prime (Initialisation)
    for(ll i=3; i<=n; i+=2)
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
            // 2. Optimisation: Take a jump of 2*i starting from i*i
            for(ll j=i*i; j<=n; j=j+i)
            {
                p[j] = 0;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);

    for(ll i=3; i<=n; i+=2)
    {
        if(p[i] == 1){
            primes.push_back(i);
        }
    }
    return primes;
}


// This returns a vector of prime factors
vector<int> factorize(int num, vector<int> &primes)
{
    vector<int> factors;
    factors.clear();

    int i = 0;
    int p = primes[0];

    while(p*p <= num)
    {
        if(num%p == 0)
        {
            factors.push_back(p);
            while(num%p == 0)
            {
                num = num/p;
            }
        }
        // go to next position
        i++;
        p = primes[i];
    }

    if(num != 1)
    {
        factors.push_back(num);
    }
    return factors;
}


// function to drive code
int main()
{
    int N = 1000000;

    int p[N] = {0};
    vector<int> primes = primeSieve(p, 100);

    int t;
    cout << "Enter testcases: ";
    cin >> t;

    while(t--)
    {
        int no;
        cout << "Enter Number: ";
        cin >> no;

        // get prime factors
        vector<int> factors = factorize(no, primes);

        cout << "Prime factors are: ";
        for(auto f : factors){
            cout << f << ", ";
        }
        cout << endl;
    }

    return 0;
}

/* 
OUTPUT:
    Enter testcases: 5

    Enter Number: 10
    Prime factors are: 2, 5, 

    Enter Number: 24
    Prime factors are: 2, 3, 

    Enter Number: 132
    Prime factors are: 2, 3, 11, 

    Enter Number: 5
    Prime factors are: 5, 

    Enter Number: 66
    Prime factors are: 2, 3, 11, 
*/
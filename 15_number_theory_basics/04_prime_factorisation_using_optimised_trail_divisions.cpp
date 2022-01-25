/*
    Topic: Prime Factorisation (using optimised trail divisions)

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

// Optimized Approach: function to return prime factor & its count
vector<pair<int,int>> primeFactors(int num)
{
    vector<pair<int,int> > factors;       // to store prime factor & its count
    int cnt;

    for(int i=2; i*i<=num; i++)
    {
        if(num%i == 0)
        {
            // keep on dividing by i till it is divisible
            cnt = 0;
            while(num%i == 0)
            {
                cnt++;
                num = num/i;
            }
            factors.push_back(make_pair(i,cnt));
        }
    }
    
    if(num!=1)
    {
        // whatever value-of-num is left, is a prime number in itself
        factors.push_back(make_pair(num,1));
    }
    
    return factors;
}

// function to drive code
int main()
{
    int t;
    cout << "Enter testcases: ";
    cin >> t;

    while(t--)
    {
        int no;
        cout << "Enter Number: ";
        cin >> no;

        // get prime factors
        vector<pair<int,int>>  factors = primeFactors(no);

        cout << "Prime factors are: ";
        for(auto f : factors){
            cout << f.first << "^" << f.second << ", ";
        }
        cout << endl;
    }

    return 0;
}

/* 

OUTPUT:
    Enter testcases: 5

    Enter Number: 24
    Prime factors are: 2^3, 3^1, 

    Enter Number: 132
    Prime factors are: 2^2, 3^1, 11^1, 

    Enter Number: 10
    Prime factors are: 2^1, 5^1, 

    Enter Number: 5
    Prime factors are: 5^1, 

    Enter Number: 66
    Prime factors are: 2^1, 3^1, 11^1, 
*/
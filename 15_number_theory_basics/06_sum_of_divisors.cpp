/*
    Topic: Sum of Divisors (using sieve)

    - Given a number n, find sum of divisors of it.
      
      Eg:   Input  : 18
            Output : 39     (i.e sum of divisors of 18 is 1+2+3+6+9+18 = 39)
        
            Input  : 100
            Output : 217    (i.e sum of divisors of 100 are 1+2+4+5+10+20+25+50+100 = 217)
    
*/

#include <iostream>
#include <vector>
using namespace std;

#define ll long long

// prime factorization using sieve
vector<int> primeSieve(int *p, int num)
{

    p[0] = p[1] = 0;      // 0 & 1 are not prime
    p[2] = 1;             // 2 is prime

    // Initilisation all odd values to 1
    for(ll i=3; i<=num; i+=2)
    {
        p[i] = 1;
    }

    // sieve
    for(ll i=3; i<=num; i+=2)
    {
        if(p[i]==1)
        {
            // mark all multiple of p[i] as 0
            for(ll j=i*i; j<=num; j=j+i)
            {
                p[j]=0;
            }
        }
    }

    vector<int> primes;
    primes.push_back(2);
    for(ll i=3; i<=num; i+=2)
    {
        if(p[i]==1)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

// finding prime factors & there exponent values
vector<pair<int,int>> primeFactorization(int num, vector<int> primes)
{
    vector<pair<int,int>> factors;
    int power_cnt = 0;
    
    int i=0;
    int p = primes[i];
    while(p<num)
    {
        power_cnt = 0;      // to store exponent value of each prime factor
        if(num%p == 0)
        {
            while(num%p==0)
            {
                power_cnt++;
                num = num/p;
            }

            factors.push_back(make_pair(p, power_cnt));
        }
        // for next iteration
        i++;
        p = primes[i];
    }

    if(num!=1)
    {
        power_cnt = 1;
        factors.push_back(make_pair(num, power_cnt));
    }

    // cout << "Prime factors: ";
    // for(auto f:factors)
    // {
    //     cout << f.first << "^" << f.second << ", ";
    // }
    // cout << endl;

    return factors;
}


// function to find sum of divisors of given number
int sum_of_divisors(int num, vector<pair<int,int>> factors)
{
    int ans = 1;
    // iterate over each prime factor
    for(auto f:factors)
    {
        int prime_factor = f.first;
        int power = f.second;
        int sum = 0;
        // lets find the sum of all possible combination that can be created from each prime factors 
        while(power)
        {
            int val = 1;
            int temp = power;
            while(temp--)
            {
                val = val*prime_factor;
            }
            sum = sum + val; 
            power--;
        }
        sum = sum + 1;         // adding 1 for the factor value 1 (i.e for prime_factor^0)
        ans = ans * (sum);     // multiply sum-of-all-possible-combinations from each prime factors 
    }
    return ans;

    /*
        APPROACH:

        1. Naive Approach

           When, N = 120
           So, All factors of 120 include 1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 20, 24, 30, 40, 60, and 120.
           Now, Sum of factors = 1+2+3+4+5+6+8+10+12+15+20+24+30+40+60+120
                               = 360
                               
        2. Optimised Approach

           We can also find sum of divisors using prime factors.
           Eg: Prime factores of 120 = 2^3, 3^1, 5^1
               sum of all of the factors of 120 (i.e 2^3 * 3 * 5) = (1 + 2 + 2^2 + 2^3) * (1+3) * (1+5)
                                                                  = 15 * 4 * 6
                                                                  = 360
     */
}


// function to drive code
int main()
{
    int N = 1000000;
    int p[N] = {0};
    // get prime number using sieve
    vector<int> primes = primeSieve(p,N);

    int t;
    cout << "Enter testcases: ";
    cin >> t;

    while(t--)
    {
        int num;
        cout << "Enter Number: ";
        cin >> num;

        // get the prime factors with its exponents
        vector<pair<int,int>> factors = primeFactorization(num,primes);

        // get sum of divisors
        int sum = sum_of_divisors(num, factors);
        
        cout << "Sum of divisors: " << sum;
        cout << endl;
    }

    return 0;
}

/* 
OUTPUT:
    Enter testcases: 4

    Enter Number: 18
    Sum of divisors: 39
    
    Enter Number: 100
    Sum of divisors: 217
    
    Enter Number: 120
    Sum of divisors: 360
    
    Enter Number: 1400
    Sum of divisors: 3720
 */
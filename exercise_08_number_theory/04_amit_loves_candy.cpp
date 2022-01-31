/*
    Problem: Amit Loves Candy

    Amit recently graduated from college. To celebrate, he went to a candy shop and bought all 
    the candies. The total cost was a number upto which there are n prime numbers (starting from 2). 
    Since Amit wants to minimize his cost, he calls you to help him find the minimum amount that needs
    to be paid. Being a student of Amit bhaiya it is now your job to help him out :)

    Input Format: First line contains a single integer denoting the number of test cases T. 
                  Next T lines contains a single integer N, denoting the number of primes required.

    Constraints: T <= 10000
                 It is guaranteed that the answer does not exceed 10^6.

    Output Format: Print the minimum cost that needs to be paid.

    Sample Input:  2
                   5
                   1

    Sample Output: 11
                    2

    Explanation:   In the first case there are 5 primes upto 11(2,3,5,7,11).
*/


#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define ll long long

int const SIZE = 10000007;
bitset<SIZE> p;
vector<ll> primes;

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
            primes.push_back(i);              // Storing all primes
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
    // get all primes
    prime_sieve();

    int t;
    cout << "Enter total testcases: ";
    cin >> t;

    while(t--)
    {
        int num;
        cout << "Enter number: ";
        cin >> num;

        cout << "Minimum Cost : ";
        cout << primes[num-1] << endl;
    }

    return 0;
}


/* 
OUTPUT:
    Enter total testcases: 2

    Enter number: 5
    Minimum Cost : 11
    
    Enter number: 1
    Minimum Cost : 2



APPROACH:

    Main logic behind the question is that you need to find the nth prime number starting from 2. 
    Any one can implement this logic "Not a big Deal" for anyone, but wait a min there's more to it.

    Many of you are getting time limit exceed right ? Even if you are using SOE (Sieve of Eratosthenes) 
    for finding the prime numbers.

    Have u see the constraint on number of test cases, It's quite large because for every test case 
    you are going to find the prime numbers upto that number and at last return the last prime number 
    found, this will cause the TLE for big test cases.

    So, to overcome this problem, let's just store your test cases in an array.
    Then find the maximum number from all of the testcases.
    then, Use SOE(Sieve of Eratosthenes) to find the prime number upto that number and store that an the array.
    After storing, simply loop over every test case that was stored previously in an array.
    Print the value of n from the array storing primes.
    That's how we need not to find the prime number for every test case. :)

*/
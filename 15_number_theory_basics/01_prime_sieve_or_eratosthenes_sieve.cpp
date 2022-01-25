/*
    Topic: Prime Sieve | Eratosthenes Sieve
    
    - Compute prime number efficiently using prime sieve
*/

#include <iostream>
using namespace std;

#define ll long long

/* Native Approach | Time Complixity = O(N)
   when printing all prime number upto n  Time Complixity = O(N*N) = O(N^2)
*/
bool isPrime(int n)
{
    if(n == 1){
        return false;
    }
    if(n == 2){
        return true;
    }
    for(int i=2; i<n; i++)
    {
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

/* Optimised Approach | Time Complixity = O(sqrt(N))
   when printing all prime number upto n  Time Complixity = O(N*sqrt(N))
 */
bool isPrimeOptimised(int n)
{
    if(n == 1){
        return false;
    }
    if(n == 2){
        return true;
    }
    for(int i=2; (i*i)<n; i++)
    {
        if(n%i == 0){
            return false;
        }
    }
    return true;
}


// Sieve Approach - Generate a array containing prime numbers | Time Complixity = O(Nloglog(N)) 
void prime_sieve(int *p, int num)
{
    // special cases
    p[0] = p[1] = 0;
    p[2] = 1;

    //first mark all odd number's as Prime (Initialisation)
    for(int i=3; i<=num; i+=2)
    {
        p[i]=1;
    }

    // Sieve Login to mark non prime numbers as 0
    // 1. Optimisation: Iterate over odd numbers
    for(ll i=3; i<=num; i+=2)
    {
        // check if the current number (at index-i) is marked (i.e it is prime)
        if(p[i]==1)
        {
            // Mark all the Multiples of that Number as Not Prime
            // for(ll j=2*i; j<=num; j=j+i){
            // 2. Optimisation: Starting from i*i instead of 2*i
            for(ll j=i*i; j<=num; j=j+i)
            {
                p[j] = 0;
            }
        }
    }
}


// function to drive code
int main()
{
    int p[1000000] = {0};
    prime_sieve(p, 1000000);

    int num;
    cout << "Find prime numbers upto: ";
    cin >> num;

    // lets print prime upto num
    cout << "All prime numbers upto " << num << " are: " << endl;
    for(int i=0; i<=num; i++)
    {
        if(p[i]==1){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}

/* 
OUTPUT:
    Find prime numbers upto: 100

    All prime numbers upto 100 are: 
    2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 

*/
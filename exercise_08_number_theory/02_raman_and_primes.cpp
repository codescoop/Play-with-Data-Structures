/*
    Problem: Raman and Primes

    Raman is learning Sieve of Eratosthenes, He is stuck somewhere. Help him printing prime numbers.

    Input Format: Single line containing integral value n.

    Constraints: 1<=n<=500000

    Output Format: Integral value denoting nth prime number.

    Sample Input: 1

    Sample Output: 2

*/


#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define ll long long

int const SIZE = 10000005;
bitset<SIZE> p;
vector<ll> primes;

void sieve()
{
    // set all bits
    p.set();

    // 0 & 1 are not prime
    p[0] = p[1] = 0;

    
    for(ll i=2; i<=SIZE; i++)
    {
        if(p[i]==1)
        {
            primes.push_back(i);
            // lets make all the multiples of i as Not Prime
            for(ll j=i*i; j<=SIZE; j=j+i)
            {
                p[j] = 0;
            }
        }
    }
}

int main()
{
    // get all prime values
    sieve();

    int pos;
    cout << "Enter position: ";
    cin >> pos;

    cout << "Prime No: ";
    cout << primes[pos-1] << endl;

    return 0;
}


/* 
OUTPUT:

Case 1:
    Enter position: 1
    Prime No: 2

Case 2:
    Enter position: 9865
    Prime No: 103123

Case 3:
    Enter position: 456
    Prime No: 3221
*/
/*
    Topic: Counting Divisors

    - Given a number n, count all distinct divisors of it.
      
      Eg:   Input : 18
            Output : 6     (i.e divisors of 18 are 1, 2, 3, 6, 9 and 18.)
        
            Input : 100
            Output : 9     (i.e divisors of 100 are 1, 2, 4, 5, 10, 20,25, 50 and 100)

    
    Approach

    1. A Naive Solution would be to iterate all the numbers from 1 to sqrt(n), 
       checking if that number divides n and incrementing number of divisors. 
       This approach takes O(sqrt(n)) time. 
    
    2. Optimized Solution: In general, it is very easy to write down the number of divisors if you 
       know the prime factorization. So,
       - find the power/exponents of the prime factors of the given number using prime factorization
       - Now, result is the product of one more than the exponents of the prime factors.
         
         Eg: Let's use a smaller example, say 60.
             As 60 = 2^2 * 3^1 * 5^1, 
             we can have either 0, 1 or 2 factors of 2, 
                         either 0 or 1 factor of 3, and 
                         either 0 or 1 factor of 5. 
             So in total, we have 3*2*2 = 12 divisors of 60. 
             You'll note that this is of the form (2+1)(1+1)(1+1), i.e the product of one more than 
             the exponents of the primes in the factorization.
        
        Thus, calculate number of divisor with below formula:
              total div of n = (p1+1) * (p2+1) *.....* (pn+1)
              
              where n = (a1^p1)*(a2^p2).... *(an^pn),
                    ai being Prime Divisor for n and 
                    pi are their respective Power in factorization
*/

#include <iostream>
#include <vector>
using namespace std;


// function to count all distinct divisors for a given number
int no_of_divisors(int num)
{
    int ans = 1;            // ans will contain total number of distinct divisors
    int power_cnt;

    for(int i=2; i*i<=num; i++)
    {
        if(num%i == 0)
        {
            // keep on dividing by i till it is divisible
            power_cnt = 0;              // to store exponents value of every prime factor
            while(num%i == 0)
            {
                power_cnt++;
                num = num/i;
            }
            ans = ans * (power_cnt+1);  // the product of one more than the exponents of prime factors
        }
    }
    
    if(num!=1)
    {
        // whatever value-of-num is left, is a prime number in itself
        power_cnt = 1;
        ans = ans * (power_cnt+1);       // the product of one more than the exponents of prime factors
    }
    
    return ans;
}


// function to drive code
int main()
{
    int t;
    cout << "Enter testcases: ";
    cin >> t;

    while(t--)
    {
        int num;
        cout << "Enter Number: ";
        cin >> num;

        // get total number of divisors
        int divisors = no_of_divisors(num);
        
        cout << "Total divisors: " << divisors << endl;
    }

    return 0;
}

/* 
OUTPUT:
    Enter testcases: 3

    Enter Number: 60
    Total divisors: 12

    Enter Number: 18
    Total divisors: 6

    Enter Number: 100
    Total divisors: 9
 */
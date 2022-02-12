/*
    Topic - Optimal Binary Strings Recursion

    # Count Binary Strings
    Given a positive integer N, count all possible distinct binary strings of length N such that 
    there are no consecutive 1’s.

    Eg: Input  : N = 3
        Output : Count = 5
        // The 5 strings are 000, 001, 010, 100, 101

        Input  : N = 2
        Output : Count = 3
        // The 3 strings are 00, 01, 10

        Explanation: When length is 2. 
                     Then there are 4 options i.e (00, 01, 10, 11) when placing binary on 2 positions.
                     Now, 11 is discarded as it has consecutive ones.
                     So, count is 3.
*/


#include <iostream>
using namespace std;


// function to Count Binary String which have No consecutive ones
int countBinaryStrings(int n, int last_digit)
{
    // base case
    if(n == 0)
    {
        return 0;
    }
    // if only one digit is left
    if(n == 1)
    {   
        if(last_digit){              // if the last digit is 1
            return 1;
        }
        else{                        // otherwise, if the last digit is 0
            return 2;
        }
    }
    
    // rec case:
    // if the last digit is 0, we can have both 0 and 1 at the current position
    if(last_digit == 0)
    {
        return countBinaryStrings(n-1, 0) + countBinaryStrings(n-1, 1) ;
    }
    // if the last digit is 1, we can only have 0 at the current position
    else
    {
        return countBinaryStrings(n-1, 0);
    }
}


// function to drive code
int main()
{
    int total_digits;
    cout << "Enter length: ";
    cin >> total_digits;

    cout << "Count: ";
    cout << countBinaryStrings(total_digits, 0);

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter length: 2
    Count: 3

Case 2:
    Enter length: 3
    Count: 5


APPROACH:
    Let f(n) give the count of binary sequences of length n without adjacent 1's.

    f(0) = 1 //There is exactly one way to list 0 items.
    f(1) = 2 //It's either a 0 or a 1.

    Now consider the addition of an nth digit. 
    If the nth digit is 0, it may be follow any legal sequence of length (n-1) 
    If the nth digit is 1, then the (n-1)th digit must be a 0. 
    These sequences can all be obtained by taking every sequence of length (n-2) and appending a 0.
    Therefore: f(n) = f(n-1) + f(n-2)
                  
                 <--(n-1)--> (last-digit)                     (n-1)  (last-digit)
                  ___________ |                            ___________ |         
                 |_|_|_|_|_|_|0|                          |_|_|_|_|_|_|1|        
                   /      \                                     |               
                  /        \                                    |               
        _________/_       __\________                      _____|_____           
       |_|_|_|_|_|0|0|   |_|_|_|_|_|1|0|                  |_|_|_|_|_|0|1|        

        When last digit is 0, then                         When last digit is 1, then
        f(n) = f(n-1) + f(n-1)                             f(n) = f(n-1)


    Eg: when n = 5

                           (5,0)
                         /        \
                       /            \
                 (4,0)                 (4,1)
               /       \                  |
          (3,0)         (3,1)           (3,0)
         /     \          |             /    \
       (2,0)    (2,1)   (2,0)        (2,0)    (2,1)
       /   \      |     /   \        /   \      | 
    (1,0) (1,1) (1,0) (1,0) (1,1) (1,0) (1,1) (1,0)

    Reference: https://www.techiedelight.com/find-n-digit-binary-strings-without-consecutive-1s/
               https://leetcode.com/discuss/general-discussion/1287402/count-number-of-binary-strings-without-consecutive-1s
*/
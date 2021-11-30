/* 
    Trailing Zero Function

    Given a interger n, write a function that return count of trailing zeros in n!

    Constraint:     1 <= N <= 10^9

    Input:      A single interger N

    Output:     A single interger denoting the count of trailing zero's in N!

    Sample Input:   5

    Sample Output:  1

    Explanation: Factorial of 5 is 120 which has one trailing zero.

*/

#include <iostream>
using namespace std;

int findZeros(int number)
{
    int divisor;
    int ans = 0;

    for (divisor = 5; number / divisor >= 1; divisor *= 5)
    {
        ans += number / divisor;
    }
    return ans;
}

int main()
{
    long long int number;

    cout << "Enter to number: ";
    cin >> number;

    cout << findZeros(number) << endl;
    return 0;
}

/* 
    Formula to calculate power of a number "D" present in N! :-

        N/D  + N/D^2 + N/D^3 + ---------- until it is greater than zero 
 */
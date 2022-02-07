/*
    Topic - Fast Power Recursion

    compute a^n
*/

#include <iostream>
using namespace std;


// compute base^power (Time complexity: O(N))
int power(int b, int p)
{
    // base case
    if(p == 0)
    {
        return 1;
    }
    // rec case
    return b * power(b, p-1); 
}


// compute base^power (Time complexity: O(LogN)
int fast_power(int b, int p)
{
    // base case
    if(p == 0)
    {
        return 1;
    }
    // rec case
    int smaller_ans = fast_power(b, p/2);
    
    // whem power is odd
    if(p&1)
    {
        return b*smaller_ans*smaller_ans;
    }
    // whem power is even 
    return smaller_ans*smaller_ans;

    /*
        APPROACH:
        
        When power is ODD:
           b^p  =   b(b^p/2)^2
        When power is EVEN:
           b^p  =   (b^p/2)^2
        
        Eg: base  = a
            power = 9
            a^9  = a*(a^8)
                       |
            (a^8) => (a^4)^2compute base^power 
                       |
            (a^4) => (a^2)^2
                       |
            (a^2) => (a^1)^2
                       |
            (a^1) =>  a(a^0)
                         |
            (a^0) =>    (1)
        So, Number of steps needed to convert p to 1 is LogN
    */
}


// function to drive code
int main()
{
    int a, b;
    cout << "Enter Numbers [a & b]: ";
    cin >> a >> b;

    cout << "a^b [Approach 1]: " << power(a,b) << endl;
    cout << "a^b [Approach 2]: " << fast_power(a,b) << endl;

    return 0;
}

/*
OUTPUT:
    Enter Numbers [a & b]: 10 4
    a^b [Approach 1]: 10000
    a^b [Approach 2]: 10000
 */

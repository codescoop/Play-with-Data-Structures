/*
    Topic - Fast Power Recursion

    compute a^n
*/

#include <iostream>
using namespace std;

// compute base^power
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


int fast_power(int b, int p)
{
    // base case
    if(p == 0)
    {
        return 1;
    }
    // rec case
    int smaller_ans = fast_power(b, p/2);
    
    // for odd
    if(b&1)
    {
        return b*smaller_ans*smaller_ans;
    }
    // for even 
    return smaller_ans*smaller_ans;
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
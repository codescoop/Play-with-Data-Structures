/* 
    Problem Name - Kth Root
    
    You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.

    Input Format: First line contains number of test cases, T. 
                  Next T lines contains integers, n and k.

    Constraints:  1<=T<=10
                  1<=N<=10^15
                  1<=K<=10^4

    Output Format: Output the integer x

    Sample Input:  2
                   10000 1
                   1000000000000000 10

    Sample Output : 10000
                    31

    Explanation:  For the first test case, for x=10000, 
                  10000^1=10000=n
*/

#include <iostream>
#include <cmath>
#define ll long long int
using namespace  std;

// function to find kth root
ll getNumber(ll result, ll exponent)
{
    /* assuming a search space & apply binary search */

    ll start = 1;              // minimum value of search space
    ll end = result;           // maximum value of search space

    ll base = 0;
    while(start <= end)
    {
        ll mid = (start+end)/2;

        if(pow(mid,exponent) == result){
            return mid;
        }
        else if(pow(mid,exponent) < result)
        {
            base = mid;           // storing the most potential value
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return base;
 }


// function to drive code
int main(){
    int testcases;
    cout << "Enter total testcases: ";
    cin >> testcases;

    while(testcases){
        ll result, exponent;
        cout << "Enter 2 integers [result & exponent]: ";
        cin >> result >> exponent;
        
        // finding maximum of minimum no of pages student can read
        ll num = getNumber(result, exponent);
        
        cout << "Greatest base value: ";
        cout << num << endl;
        testcases--;
    }

    return 0;
}


/* 
OUTPUT:

    Enter total testcases: 2

    Enter 2 integers [result & exponent]: 10000 1
    Greatest base value: 10000

    Enter 2 integers [result & exponent]: 1000000000000000 10
    Greatest base value: 31

APPROACH:

    We will apply binary search in this problem. For every possible mid obtained by using binary search 
    we will check of it is the best suitable candidate or not for becoming the Kth root and then we 
    reduce the search space of the binary search according to the mid value. 
    If mid^k is greater than N, then we will find the best suitable value from left to mid-1 otherwise
    we will find much larger value by finding it from mid+1 to right.
*/
/*
    Problem Name: Incredible Hulk

    The Planet Earth is under a threat from the aliens of the outer space and the Marvel Avengers team is
    busy fighting against them. Meanwhile, The Incredible Hulk has to defeat an enemy who is N steps above
    the level where he is standing (assume it as the 0th level). 
    Hulk, because of his incredible jumping ability can take jumps in power of 2. In order to defeat 
    the enemy as quickly as possible he has to reach the Nth step in minimum moves possible. 
    Help Hulk to find the same and contribute in saving the Mother Earth.

    Input Format: The first line contains the number of test cases T. 
                  T test cases follow: The first line of each test case contains a number N.

    Constraints:  1 <= T <= 10
                  1 <= N <= 10^5

    Output Format: Output T lines, containing the minimum number of moves required by Hulk to reach 
                   the Nth step

    Sample Input:  3
                   3
                   4
                   5

    Sample Output:  2
                    1
                    2

    Explanation:  Let total steps is n, find the nearest integer which is of power 2 and less then n. 
                  let it would be k. 
                  now remaining steps to cover is n-k and result = 1 + min steps for (n-k) remaining steps.
*/


#include <iostream>
using namespace std;

// function to find minimum moves possible (i.e Count the number of set bits)
int getMinSteps(int n)
{
    int steps = 0;
    while(n)
    {
        n = n & (n-1);        // removing the last set bits
        steps++;              // steps is the no. of times loop run
    }
    return steps;
}


// function to drive code
int main()
{
    int testcase;
    cout << "Enter total testcases: ";
    cin >> testcase;

    while(testcase--)
    {
        int distance;
        cout << "Enter Enemy Distance: ";
        cin >> distance;

        cout << "Minimum no of moves: ";
        cout << getMinSteps(distance) << endl;
    }
    return 0;
}

/* 
OUTPUT:

    Enter total testcases: 3

    Enter Enemy Distance: 3
    Minimum no of moves: 2

    Enter Enemy Distance: 4
    Minimum no of moves: 1

    Enter Enemy Distance: 5
    Minimum no of moves: 2


APPROACH:

    In short the Question is to find he highest power of 2 which is smaller than or equals to the 
    given number.

Algo:

    - Check if the number is power of 2. (For e.g., n = 4 so 4 & 3 == 1 ? hence power of 2.)
         1.1 If yes then return 1.
    - Count the number of set bits.
    - This count is the answer.

Code: (JAVA)

    public static int minSteps(int n) 
    {
        if ((n & (n - 1)) == 1)
            return 1;

        int sum = 0;
        int mask = n;

        while (mask != 0) 
        {
            sum += mask & 1;
            mask >>= 1;
        }
        return sum;
    }
*/
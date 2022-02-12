/*
    Topic - Ladders Problem (Recursion)

    # Climbing Stairs
    You are climbing a staircase. It takes N steps to reach the top.

    1. Each time you can either climb 1,2 or 3 steps. In how many distinct ways can you climb to the top?
        Eg: Input: n = 2
            Output: 2
            Explanation: There are two ways to climb to the top.
                        - 1 step + 1 step
                        - 2 steps
            
            Input: n = 3
            Output: 4
            Explanation: There are three ways to climb to the top.
                        - 1 step + 1 step + 1 step
                        - 1 step + 2 steps
                        - 2 steps + 1 step
                        - 3 steps

    2. Each time you can either climb upto k steps. In how many distinct ways can you climb to the top?

*/

#include <iostream>
using namespace std;


// function to get total number of ways to climb N stairs (when each time we can either climb 1,2 or 3 steps)
int getNoOfWays(int totalSteps)
{
    // base case
    if(totalSteps == 0)
    {
        return 1;
    }
    if(totalSteps < 0)
    {
        return 0;
    }
    // rec case:
    int x = getNoOfWays(totalSteps-1);
    int y = getNoOfWays(totalSteps-2);
    int z = getNoOfWays(totalSteps-3);

    return x+y+z;
}


// function to get total number of ways to climb N stairs (when each time we can either climb upto k steps)
int getNoOfWaysUptoKSteps(int totalSteps, int k )
{
    // base case
    if(totalSteps == 0)
    {
        return 1;
    }
    if(totalSteps < 0)
    {
        return 0;
    }
    // rec case:
    int ans = 0;
    for(int i=1; i<=k; i++)
    {
        ans += getNoOfWaysUptoKSteps(totalSteps-i, k);
    }

    return ans;
    /* 
                  f(N)                   ans = 0
                 / |   \
                /  |     \
               /   |       \
          f(n-1) f(n-1).... f(n-k)
           a       b ........  z         ans = a + b +.....+ z
    */
}


// function to drive code
int main()
{
    int steps;
    cout << "Enter total steps: ";
    cin >> steps;

    int k;
    cout << "Upto how many steps we can climb [Enter k]: ";
    cin >> k;
    
    cout << "Distinct ways to climb staircase [upto k steps]: ";
    cout << getNoOfWaysUptoKSteps(steps, k);         // can take upto k steps

    cout << "\nDistinct ways to climb staircase [1,2,3 steps]: ";
    cout << getNoOfWays(steps);                      // can take either 1, 2 or 3 steps

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter total steps: 2
    Upto how many steps we can climb [Enter k]: 3
    Distinct ways to climb staircase [upto k steps]: 2
    Distinct ways to climb staircase [1,2,3 steps]: 2

Case 2:
    Enter total steps: 3
    Upto how many steps we can climb [Enter k]: 3
    Distinct ways to climb staircase [upto k steps]: 4
    Distinct ways to climb staircase [1,2,3 steps]: 4

Case 3:
    Enter total steps: 4
    Upto how many steps we can climb [Enter k]: 1
    Distinct ways to climb staircase [upto k steps]: 1
    Distinct ways to climb staircase [1,2,3 steps]: 7

Case 4:
    Enter total steps: 5
    Upto how many steps we can climb [Enter k]: 1
    Distinct ways to climb staircase [upto k steps]: 1
    Distinct ways to climb staircase [1,2,3 steps]: 13


APPROACH:

    We can easily find the recursive nature in the above problem. 
    - The person can reach nth stair from either (n-1)th stair or from (n-2)th stair. Hence, for 
      each stair n, we try to find out the number of ways to reach n-1th stair and n-2th stair and add them
      to give the answer for the nth stair. 
    - Therefore the expression for such an approach comes out to be :   ways(n) = ways(n-1) + ways(n-2)

                                                                              O
                                                                             `|` 
                                                                           __/ \__  FINISH (N steps)
                                                                    ______|(N-1)steps
                                                             ______|(N-2)steps
                                                      ______|(N-3)steps          (as we can climb either 1,2 or 3 steps)
                                               ______|
                                        ______|
                     O           ______|
                    `|`   ______|
                  __/ \__|
                   START (0 steps)
*/
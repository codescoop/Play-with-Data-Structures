/* 
    Topic - Aggressive Cows

    Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
    The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
    
    His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other 
    once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows
    to the stalls, such that the minimum distance between any two of them is as large as possible. 
    What is the largest minimum distance?

    Input Format:  First line contains N and C, separated by a single space, representing the total 
                   number of stalls and number of cows respectively. 
                   The next line contains N integers containing the indexes of stalls.

    Constraints:  2 <= N <= 100,000
                  0 <= xi <= 1,000,000,000
                  2 <= C <= N

    Output Format: Print one integer: the largest minimum distance.

    Input:  5 3
            1
            2
            8
            4
            9

    Output: 3

    Explanation:  FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
                  resulting in a minimum distance of 3.
*/

#include <iostream>
#include <algorithm>
#define ll long long int
using namespace  std;

// function to check if cow can be seprated by this distance
bool canPlaceCowAtThisSepration(ll stalls[], ll totalStalls, ll totalCows, ll given_sepration)
{
    ll prev_stall_location = stalls[0];
    ll cowCount = 1;
    
    for(ll idx=1; idx<=totalStalls-1; idx++)
    {
        ll curr_stall_location = stalls[idx];
        // placing the cow if distance is greater than given distance
        if((curr_stall_location - prev_stall_location) >= given_sepration)
        {
            prev_stall_location = curr_stall_location;    // assign this location to the cow
            cowCount++;
            if(cowCount == totalCows){
                return true;
            }
        }
    }
    return false;
}



// function to find largest minimum distance
ll getDistance(ll *stalls, ll totalStalls, ll totalCows)
{
    /* assuming search space for cow sepration:
       - minimum distance at which cow can be placed/seprated = 0
       - maximum distance at which cow can be placed/seprated = (last stall location value - first stall location value)
       Now apply binary search on this search space i.e [0 to (last stall location - first stall location)]
    */
    ll start = 0;                                      // minimum cow sepration distance
    ll end = stalls[totalStalls-1] - stalls[0];        // maximum cow sepration distance

    ll distance = 0;
    while(start <= end)
    {
        ll mid = (start+end)/2;

        bool cowSeprationStatus = canPlaceCowAtThisSepration(stalls, totalStalls, totalCows, mid);

        if(cowSeprationStatus){
            distance = mid;              // getting most potential distance value
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return distance;                    // return final distance value
}



// function to drive code
int main()
{
    ll totalStalls, totalCows;
    cout << "Enter number of stalls & cows: ";
    cin >> totalStalls >> totalCows;
    
    ll stalls[totalStalls];
    cout << "Enter stalls locations: ";
    for(ll idx=0; idx<=totalStalls-1; idx++){
        cin >> stalls[idx] ;
    }

    // sorting stalls
    sort(stalls, stalls+totalStalls);

    // finding largest minimum distance
    ll result = getDistance(stalls, totalStalls, totalCows);
    
    cout << "Largest Minimum distance: ";
    cout << result << endl;

    return 0;
}

/* 
OUTPUT:

    Enter number of stalls & cows: 5 3
    Enter stalls locations: 1 2 8 4 9
    Largest Minimum distance: 3



APPROACH:
    
    For this problem, fix one cow at the first position and then move ahead.
    
    So I have created a minimum Distance function which basically calculates a mid point and treats that 
    as the minimum distance to place a cow. 
    If we have a position greater than or equal to this distance, we fix the cow at that position.
    
    long minDist(long stalls[],int n,int k)
    {
        int s = stalls[0];
        int e = stalls[n-1];

        int ans = 0;
        int mid = 0;
        while(s+1<e){      //here if you take s<e, it will become an infinite loop once we reach the required answer.
            mid = (s+e)/2;

            if(isValid(stalls,n,k,mid)==1){
                s = mid;
            }
            else{
                e = mid;
            }
        }
        return s;
    }

    Now the isValid Function takes as input the the minimum distance (or the mid point), number of cows, 
    the array of stall positions and size of the array

    int isValid(long stalls[],int n,int s,int current_ans)
    {
        int cow = 1;
        int currently_alloted = stalls[0];

        for(int i=1;i<n;i++)
        {
            if(stalls[i]-currently_alloted >= current_ans)
            {
                cow++;
                if(cow==s)
                {
                    return 1;
                }
                currently_alloted = stalls[i];

            }
        }
        return 0;
    }

    Now all you need to do is call the minDist function in your main. Hope this helps!!

*/
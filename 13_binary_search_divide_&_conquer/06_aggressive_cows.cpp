/* 
    Topic - Aggressive Cows

    Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
    The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
    His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other 
    once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows
    to the stalls, such that the minimum distance between any two of them is as large as possible. 
    What is the largest minimum distance?

    Input Format:  t – the number of test cases, then t test cases follows.
                   Line 1: Two space-separated integers: N and C
                   Lines 2..N+1: Line i+1 contains an integer stall location, xi

    Output Format: For each test case output one integer: the largest minimum distance.

    Input:  1
            5 3
            1
            2
            8
            4
            9

    Output: 3

    Output details: FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
                    resulting in a minimum distance of 3.
*/

#include <iostream>
#include <algorithm>
using namespace  std;

// function to check if cow can be seprated by this distance
bool canPlaceCowAtThisSepration(int stalls[], int totalStalls, int totalCows, int min_sepration)
{
    // place the cow at first stall
    int prevCowStallLocation = stalls[0];    // variable to maintain the state of previous cow location
    int cowsCount = 1;                       // maintaining the count of no of cows placed at stalls
   
    for(int idx=1; idx<=totalStalls-1; idx++)
    {
        int currentStallLocation = stalls[idx];
        
        // placing the cow if distance is greater than minimum distance
        if((currentStallLocation-prevCowStallLocation) >= min_sepration )
        {
            prevCowStallLocation = currentStallLocation;       // assign this location to the cow
            cowsCount++;                                       // increment cow count
            if(cowsCount == totalCows){
                return true;
            }
        }
    }
    return false;
}



// function to find largest minimum distance
int getDistance(int *stalls, int totalStalls, int totalCows)
{
    /* assuming search space for cow sepration:
       - minimum distance at which cow can be placed/seprated = 0
       - maximum distance at which cow can be placed/seprated = (last stall location value - first stall location value)
       Now apply binary search on this search space i.e [0 to (last stall location - first stall location)]
    */
    int start = 0;                                      // minimum cow sepration distance
    int end = stalls[totalStalls-1] - stalls[0];        // maximum cow sepration distance

    int distance = 0;
    while(start <= end)
    {
        int mid = (start+end)/2;

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
int main(){
    int testcases;
    cout << "Enter total testcases: ";
    cin >> testcases;

    while(testcases){
        int totalStalls, totalCows;
        cout << "Enter number of stalls & cows: ";
        cin >> totalStalls >> totalCows;
        
        int stalls[totalStalls];
        cout << "Enter stalls locations: ";
        for(int idx=0; idx<=totalStalls-1; idx++){
            cin >> stalls[idx] ;
        }

        // sorting stalls
        sort(stalls, stalls+totalStalls);

        // finding largest minimum distance
        int result = getDistance(stalls, totalStalls, totalCows);
        
        cout << "Largest Minimum distance: ";
        cout << result << endl;

        testcases--;
    }

    return 0;
}


/* 
OUTPUT:

    Enter total testcases: 1
    Enter number of stalls & cows: 5 3
    Enter stalls locations: 1 2 4 8 9
    Largest Minimum distance: 3
*/
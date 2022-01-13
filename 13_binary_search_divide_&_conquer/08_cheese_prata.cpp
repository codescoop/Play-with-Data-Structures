/* 
    Topic - PRATA (SPOJ.com)
    
    IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. 
    The subcommittee members are asked to go to food connection and get P(P<=1000) pratas packed for 
    the function. The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8). 
    
    A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the next 2R minutes, 
    1 more prata in 3R minutes and so on(he can only cook a complete prata) 
    
    (For example: If a cook is ranked 2.. he will cook one prata in 2 minutes one more prata in the next
     4 mins an one more in the next 6 minutes. Hence in total(2+4+6) 12 minutes he cooks(1+1+1) 3 pratas.
     In 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). 
    
    The webmaster wants to know the minimum time to get the order done. Please write a program to 
    help him out.

    Input Format : The first line tells the number of test cases. Each test case consist of 2 lines. 
                   In the first line of the test case we have P the number of prata ordered. 
                   In the next line the first integer denotes the number of cooks L and next L integers
                   follow in the same line each denoting the rank of a cook.

    Output Format: Print an integer which tells the number of minutes needed to get the order done.

    Input:  3
            10
            4 1 2 3 4
            8
            1 1
            8
            8 1 1 1 1 1 1 1 1

    Output: 12
            36
            1
*/

#include <iostream>
#include <climits>
using namespace  std;

// function to check if it is possible to cook all prata in the given time
bool isPossible(int rank[], int totalCooks, int totalPrata, int given_cooking_time){
    int prataCount = 0;
    for(int idx=0; idx<=totalCooks-1; idx++)
    {
        int time_taken_by_each_cook = 0;
        int time_multiplier = 1;
        while(time_taken_by_each_cook <= given_cooking_time)
        {
            time_taken_by_each_cook = time_taken_by_each_cook + (rank[idx]*time_multiplier);
            // increase prata count if time taken by cook is less then given time
            if(time_taken_by_each_cook <= given_cooking_time){
                prataCount++;
            }
            // check if all the pranta has been cooked
            if(prataCount == totalPrata){
                return true;
            }
            time_multiplier++;
        }
    }
    return false;
}


// function to find minimum time taken to cook all prata
int getOrderTime(int *rank, int totalCooks, int totalPrata){
    /* Assuming the search space for Number of Minutes & 
       appling binary search on this time range */

    // Max time taken by cook (i.e Time take to cook all prata by the cook having last rank)
    int time_taken_by_cook_with_max_rank = ((totalPrata/2)*(totalPrata+1))*rank[totalCooks-1];

    int start = 1;
    int end = time_taken_by_cook_with_max_rank;
    int timeTaken = INT_MAX;

    while(start<=end)
    {
        int mid = (start+end)/2;

        // check if it is possible to cook all prata in given time (i.e mid value)
        int status = isPossible(rank, totalCooks, totalPrata, mid);

        if(status){
            // if it is possible to cook order in x minutes
            timeTaken = min(timeTaken, mid);     // store minimum value from the eligible time values
            end = mid-1;
        }else{
            // if it is not possible to cook order in x minutes
            start = mid+1;
        }
    }
    return timeTaken;
}


// function to drive code
int main(){
    int testcases;
    cout << "Enter total testcases: ";
    cin >> testcases;

    while(testcases){
        int totalPrata, totalCooks;
        cout << "Enter number of Prata & Cook: ";
        cin >> totalPrata >> totalCooks;
        
        int rank[totalCooks];
        cout << "Enter rank of cook: ";
        for(int idx=0; idx<=totalCooks-1; idx++){
            cin >> rank[idx] ;
        }

        // finding minimum number of minutes needed to get the order done
        int timeTaken = getOrderTime(rank, totalCooks, totalPrata);
        
        cout << "Minimum Order time: ";
        cout << timeTaken << endl;

        testcases--;
    }

    return 0;
}


/* 
OUTPUT:

Enter total testcases: 3

Enter number of Prata & Cook: 10 4
Enter rank of cook: 1 2 3 4
Minimum Order time: 12

Enter number of Prata & Cook: 8 1
Enter rank of cook: 1
Minimum Order time: 36

Enter number of Prata & Cook: 8 8
Enter rank of cook: 1 1 1 1 1 1 1 1
Minimum Order time: 1

*/
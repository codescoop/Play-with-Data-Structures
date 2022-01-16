/* 
    Problem - Find Upper and Lower bound

    Find position of the last and first occurrence of a given number in a sorted array. 
    If number does not exist then print lower and upper bound as -1.

    Input Format: First line contains an integer n denoting the size of the array.
                  Second line contains n space separated integers denoting array elements.
                  Third line contains single integer Q denoting the no of queries.
                  Q lines follow , each containing a single integer x that is to be searched in the array.

    Constraints:  1 <= N <= 10^5
                  1 <= Q <= 100

    Output Format: For each query , print the lowerbound and the upperbound for the number x in a 
                   new line each.

    Sample Input:   5
                    1 2 3 3 4
                    3
                    2
                    3
                    10

    Sample Output:  1 1
                    2 3
                   -1 -1

    Explanation: The first and the last occurrence of 2 in the given array are both 1.
                 The first occurrence of 3 is at index=2 and last at index=3.
                 10 is not present in the array so we print -1 for it.

*/

#include <iostream>
#include <algorithm>
using namespace std;

int first_occurance(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;

    int first_idx = -1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        
        if(key <= arr[mid])
        {
            first_idx = mid;
            end = mid-1;
        }
        else if(key <= arr[mid])
        {
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return first_idx;
}

int last_occurance(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;

    int last_idx = -1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        
        if(key == arr[mid])
        {
            last_idx = mid;
            start = mid+1;
        }
        else if(key > arr[mid])
        {
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return last_idx;
}

// function to drive code
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter array elements: ";
    for (int index = 0; index < size; index++)
    {
        cin >> arr[index];
    }

    int total_queries;
    cout << "Enter no of queries: ";
    cin >> total_queries;

    while(total_queries--)
    {
        int key;
        cout << "Enter Search Key: ";
        cin >> key;

        // First & Last Occurance
        int first_idx = first_occurance(arr,size,key);
        int last_idx = last_occurance(arr,size,key);

        // Print Values
        cout << key << ": first Occurance: " << first_idx;
        cout << " | Last Occurance: " << last_idx << endl;
    }

    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter array size: 5
    Enter array elements: 1 2 3 3 4
    Enter no of queries: 3

    Enter Search Key: 3
    3: first Occurance: 2 | Last Occurance: 3

    Enter Search Key: 2
    2: first Occurance: 1 | Last Occurance: 1

    Enter Search Key: 10
    10: first Occurance: -1 | Last Occurance: -1

Case 2:
    Enter array size: 12
    Enter array elements: 1 1 1 2 3 4 5 6 9 9 9 10
    Enter no of queries: 4
    
    Enter Search Key: 1
    1: first Occurance: 0 | Last Occurance: 2

    Enter Search Key: 9
    9: first Occurance: 8 | Last Occurance: 10

    Enter Search Key: 5
    5: first Occurance: 6 | Last Occurance: 6

    Enter Search Key: 11
    11: first Occurance: -1 | Last Occurance: -1


APPROACH:

    The overall algorithm works fairly similarly to the linear scan approach, except for the subroutine 
    used to find the left and rightmost indices themselves. 
    Here, we use a modified binary search to search a sorted array, with a few minor adjustments. 
    First, because we are locating the leftmost (or rightmost) index containing target (rather than 
    returning true iff we find target), the algorithm does not terminate as soon as we find a match. 
    Instead, we continue to search until lo == hi and they contain some index at which target 
    can be found.

    The other change is the introduction of the left parameter, which is a boolean indicating what to
    do in the event that target == nums[mid]; if left is true, then we "recurse" on the left subarray 
    on ties. Otherwise, we go right. To see why this is correct, consider the situation where we find 
    target at index i. The leftmost target cannot occur at any index greater than i, so we never need 
    to consider the right subarray. The same argument applies to the rightmost index.

*/

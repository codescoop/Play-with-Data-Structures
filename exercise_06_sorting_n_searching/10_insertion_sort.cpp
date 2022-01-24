/* 
    Topic - Insertion Sort

    Given an array A of size N , write a function that implements insertion sort on the array. 
    Print the elements of sorted array.

    Input Format: First line contains a single integer N denoting the size of the array. 
                  Next line contains N space seperated integers where ith integer is the ith element of the array.

    Constraints:   1 <= N <= 1000
                   |Ai| <= 1000000

    Output Format:  Output N space seperated integers of the sorted array in a single line.

    Sample Input:   4
                    3 4 2 1

    Sample Output:  1 2 3 4

    Explanation:  For each test case, write insertion sort to sort the array.
*/

#include <iostream>
#define ll long long int

using namespace  std;


void insertion_sort(ll *arr, ll size)
{
    // loop for unsorted array
    for(ll i=1; i<=size-1; i++)
    {
        ll curr = arr[i];
        // placing "current" element on right position in sorted array
        ll j = i-1;
        while(arr[j] > curr && j>=0)
        {   
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}

// function to drive code
int main()
{
    ll size;
    cout << "Enter array size: ";
    cin >> size;
    
    ll arr[size];
    cout << "Enter array elements: ";
    for(ll idx=0; idx<=size-1; idx++){
        cin >> arr[idx] ;
    }

    // sorting array
    insertion_sort(arr, size);

    // print sorted array
    cout << "Sorted Array: ";
    for(ll idx=0; idx<=size-1; idx++){
        cout << arr[idx] << " " ;
    }
    cout << endl;

    return 0;
}
       
/* 
OUTPUT:

Case 1:
    Enter array size: 5
    Enter array elements: 5 2 1 4 3
    Sorted Array: 1 2 3 4 5

Case 2:
    Enter array size: 4
    Enter array elements: 2 -18 45 30
    Sorted Array: -18 2 30 45 


APPROACH:

   Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time.
   
   Algorithm:
    Step 1 − First element is already sorted.
    Step 2 − Pick next element
    Step 3 − Compare with all elements in the sorted sub-list
    Step 4 − Shift all the elements in the sorted sub-list that is greater than the value to be sorted
    Step 5 − Insert the value
    Step 6 − Repeat steps 2,3,4,5 until list is sorted
*/
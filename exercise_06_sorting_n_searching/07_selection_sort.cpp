/* 
    Topic - Selection Sort

    Take as input N, the size of array. Take N more inputs and store that in an array. 
    Write a function that selection sorts the array. Print the elements of sorted array.
    1.It reads a number N.
    2.Take Another N numbers as input and store them in an Array.
    3.Sort the array using Selection Sort and print that Array.

    Constraints:  N cannot be Negative. 
                  Range of Numbers can be between -1000000000 to 1000000000.

    Sample Input:    4
                     2
                   -18
                    45
                    30

    Sample Output: -18
                     2
                    30
                    45

    Explanation:  Write selection sort to sort the given integers in the problem.
*/

#include <iostream>
#define ll long long int

using namespace  std;


void selection_sort(ll *arr, ll size)
{
    // loop for moving boundary of unsorted array
    for(ll i=0; i<=size-2; i++)
    {
        // find out the smallest index in unsorted part
        ll min_index = i;
        for(ll j=i+1; j<=size-1; j++)
        {   
            if(arr[j] < arr[min_index]){
                min_index = j;
            }    
        }
        // Swap first element with the min value
        swap(arr[i], arr[min_index]);
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
    selection_sort(arr, size);

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

    The selection sort algorithm sorts an array by repeatedly finding the minimum element 
    (considering ascending order) from unsorted part and putting it at the beginning.
    The algorithm maintains two subarrays in a given array.

    1) The subarray which is already sorted.
    2) Remaining subarray which is unsorted.

    In every iteration of selection sort, the minimum element (considering ascending order) 
    from the unsorted subarray is picked and moved to the sorted subarray. 

*/
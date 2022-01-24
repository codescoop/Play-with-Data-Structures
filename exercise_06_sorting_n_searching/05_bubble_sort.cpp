/* 
    Topic - Bubble Sort
    
    Take as input N, the size of array. Take N more inputs and store that in an array. 
    Write a function that bubble sorts the array. Print the elements of sorted array.

    1.It reads a number N.
    2.Take Another N numbers as input and store them in an Array.
    3.Bubble sort the array and print the Array.

    Constraints: N cannot be Negative. 
                 Range of Numbers can be between -1000000000 to 100000000.

    Sample Input:    4
                     2
                   -18
                    45
                    30

    Sample Output: -18
                     2
                    30
                    45

    Explanation: For each test case write bubble sorting program to sort the elements of the array.
*/

#include <iostream>
#define ll long long int

using namespace  std;


void bubble_sort(ll *arr, ll size)
{
    // counting steps
    for(ll step=1; step<=size-1; step++)
    {
        // iterating unsorted array
        for(ll idx=0; idx<=(size-1)-step; idx++)
        {   
            // pairwise swapping
            if(arr[idx] > arr[idx+1]){
                swap(arr[idx], arr[idx+1]);
            }    
        }
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
    bubble_sort(arr, size);

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
    Enter array elements: 5 1 2 3 4 
    Sorted Array: 1 2 3 4 5 

Case2: 
    Enter array size: 4
    Enter array elements: 2 -18 45 30
    Sorted Array: -18 2 30 45


APPROACH:

    Bubble sort is comparison-based algorithm in which each pair of adjacent elements is compared 
    and the elements are swapped if they are not in order. 

*/
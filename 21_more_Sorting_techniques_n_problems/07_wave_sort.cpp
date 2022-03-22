/*
    Topic - Wave Sort (Sort an array in wave form)

    Given an unsorted array of integers, sort the array into a wave like array. 
    An array ‘arr[0..n-1]’ is sorted in wave form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..

    Examples:    Input:  arr[] = {10, 5, 6, 3, 2, 20, 100, 80}
                 Output: arr[] = {10, 5, 6, 2, 20, 3, 100, 80} OR
                                 {20, 5, 10, 2, 80, 6, 100, 3} OR
                                 any other array that is in wave form

    APPROACH-I
    - A Simple Solution is to use sorting. First sort the input array, then swap all adjacent elements.
      The time complexity is O(nLogn) if a O(nLogn) sorting algorithm like Merge Sort,Heap Sort, etc is used.
      For example, let the input array be {3, 6, 5, 10, 7, 20}. 
                   After sorting, we get {3, 5, 6, 7, 10, 20}. 
                   After swapping adjacent elements, we get {5, 3, 7, 6, 20, 10}.
    
    APPROACH-II
    -  If we make sure that all even positioned (at index 0, 2, 4, ..) elements are greater than their
       adjacent odd elements, we don’t need to worry about odd positioned element.
    -  The time complexity is O(n) as we are doing a single traversal of given array.
       
      Following are simple steps. 
        1) Traverse all even positioned elements of input array, and do following. 
           a) If current element is smaller than previous odd element, swap previous and current. 
           b) If current element is smaller than next odd element, swap next and current.
*/

#include <iostream>
using namespace std;

// sort an array in wave form
void sortInWave(int arr[], int size)
{
    for(int i=0; i<size; i+=2)
    {
        // check all Prev element except starting index
        if(i != 0 and arr[i] < arr[i-1])
        {
            swap(arr[i],arr[i-1]);
        }
        // check all Next element except last index
        if(i != (size-1) and arr[i] < arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
}


// function to drive code
int main()
{
    int arr[] = {1,3,4,2,7,4};
    int size = sizeof(arr)/sizeof(int);

    cout << "Array: ";
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }

    sortInWave(arr, size);

    cout << "\nWave Sorting: ";
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}


/*
OUTPUT:
    Array: 1 3 4 2 7 4 
    Wave Sorting: 3 1 4 2 7 4

*/
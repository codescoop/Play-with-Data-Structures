/*
    Topic - Inversion Count

    Given an array of integers. Find the Inversion Count in the array. 

    Inversion Count: For an array, inversion count indicates how far(or close) the array is from being sorted. 
                     If array is already sorted then the inversion count is 0. If an array is sorted in
                     the reverse order then the inversion count is the maximum. 
                     Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

    Eg: Input      : N = 5, arr[] = {2, 4, 1, 3, 5}
        Output     : 3
        Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

        Input: N = 5, arr[] = {2, 3, 4, 5, 6}
        Output: 0
        Explanation: As the sequence is already sorted so there is no inversion count.

        Input: N = 3, arr[] = {10, 10, 10}
        Output: 0
        Explanation: As all the elements of array are same, so there is no inversion count.
*/

#include <iostream>
using namespace std;

// function to compute cross inversion count for two subarrays
int merge(int *arr, int start, int mid, int end)
{
    int i = start;              // pointer for left subarray
    int j = mid + 1;            // pointer for right subarray
    int k = start;              // pointer for temp array 

    int temp[start + end + 1];  // create temp array to store merged values

    int count = 0;              // to store count for cross inversion

    // Merge the two subarrays back into temp array in sorted order
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count += mid - (i-1);            // cross inversion as a[i] > a[j]
        }
    }
    // Merge the remaining elements of left subarray, if there are any
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    // Merge the remaining elements of right subarray, if there are any
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    // Copy all elements of temp array into original array
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }
    return count;

    /* 
        Explanation: when  a[i] > a[j] 
                     count += mid -i +1;
        Eg:  
             _____i_____mid     ________
             |_|_|5|6|7|8|    |_|2|_|_| 
                  |              |
                 a[i]           a[j]

            So, how many index we have from i to mid (i.e cross inversion) => mid - (i-1)
                                                                           =  mid -i +1
    */
}


// funtion to compute inversion count using merge sort
int inversion_count(int *arr, int start, int end)
{
    // base case: for 0 or 1 elements
    if (start >= end)
    {
        return 0;
    }

    // rec case: using merge sort
    int mid = start + (end - start) / 2;

    // Divide: recursively divide the array in two halves - [start,mid] & [mid+1,end], until base case i.e sorted
    int x = inversion_count(arr, start, mid);
    int y = inversion_count(arr, mid + 1, end);
    // counting cross inversion when merging two sorted halves
    int z =  merge(arr, start, mid, end);
    
    return x+y+z;
}


// function to drive code
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter Elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Inversion Count: " << inversion_count(arr, 0, size-1);

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter array size: 5
    Enter Elements: 2 4 1 3 5
    Inversion Count: 3

Case 2:
    Enter array size: 6
    Enter Elements: 1 5 2 6 3 0
    Inversion Count: 8

Case 3:
    Enter array size: 5
    Enter Elements: 2 3 4 5 6
    Inversion Count: 0

Case 4:
    Enter array size: 3
    Enter Elements: 10 10 10 10
    Inversion Count: 0
 */
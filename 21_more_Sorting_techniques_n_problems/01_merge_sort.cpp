/*
    Topic - Merge Sort

    Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves,
    calls itself for the two halves, and then merges the two sorted halves. The merge() function
    is used for merging two halves.

    Eg: n=6, arr = {5,6,1,2,4,0}

                                n
                     |5|6|1|2|4|0|          m = (s+e)/2 = (0+5)/2 = 2
                      s / m   \ e
                  |5|6|1|     |2|4|0|       Divide
                   s/  \m   m+1/    \e
                |5|6|  |1|  |2|4|   |0|
                /  \    |     /  \   |
              |5|  |6|  |  |2|  |4|  |
                \   /   |    \   /   |
                |5|6|   |    |2|4|   |      Sort & Merge
                    \   |        \   |
                   |1|5|6|      |0|2|4|
                    i  \         j /
                       |0|1|2|4|5|6|
                        k
*/

#include <iostream>
using namespace std;

// function to merge two subarrays using 2-pointers approach
void merge(int *arr, int start, int mid, int end)
{
    int i = start;              // pointer for left subarray
    int j = mid + 1;            // pointer for right subarray
    int k = start;              // pointer for temp array 

    int temp[start + end + 1];  // create temp array to store merged values

    // Merge the two subarrays back into temp array in sorted order
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
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
}


// Merge Sort
void merge_sort(int *arr, int start, int end)
{
    // base case: for 0 or 1 elements
    if (start >= end)
    {
        return;
    }

    // rec case
    int mid = start + (end - start) / 2;

    // Divide: recursively divide the array in two halves - [start,mid] & [mid+1,end], until base case i.e sorted
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    // Merge the two sorted halves
    merge(arr, start, mid, end);
    return;
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

    // sort array
    merge_sort(arr, 0, size-1);

    cout << "After Merge Sort: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

/*
OUTPUT:
    Enter array size: 5
    Enter Elements: 5 4 3 1 2
    After Merge Sort: 1 2 3 4 5
 */
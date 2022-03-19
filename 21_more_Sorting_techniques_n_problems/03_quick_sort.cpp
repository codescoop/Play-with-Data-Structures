/*
    Topic - Quick Sort

    - It is a inplace algorithm
    - Divide & Conquer
    - NlogN on avg case
    - N^2 on worst case (can be fixed using randomised quick sort )
*/

#include <iostream>
using namespace std;

// Partition function: Divide the array in 2 parts using pivot element i.e elements<=pivot & elements >pivot
int partition(int *arr, int start, int end)
{
    // Inplace (can't take extra array)

    int i = start-1;   // pointer for maintaning region smaller than pivot
    int j = start;     // pointer for maintaning region larger than pivot

    int pivot = end;   // pivot is the last array element
    
    // divide the array in smaller & larger region on the bases of pivot element
    while(j<end)
    {
        if(arr[j] <= arr[pivot])
        {
            i++;
            swap(arr[j], arr[i]);
        }
        j++;
    }
    // place the pivot element at its correct position
    swap(arr[i+1], arr[pivot]);
    // return the pivot index
    return i+1;

    
}

// quick Sort
void quick_sort(int *arr, int start, int end)
{
    // base case: for 0 & 1 element
    if (start >= end)
    {
        return;
    }
    // rec case
    int p_idx = partition(arr, start, end);
    // left subarray
    quick_sort(arr, start, p_idx-1);
    // right subarray
    quick_sort(arr, p_idx+1, end);
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
    quick_sort(arr, 0, size - 1);

    cout << "After Quick Sort: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}

/*
OUTPUT:
    Enter array size: 7
    Enter Elements: 2 7 8 6 1 5 4
    After Quick Sort: 1 2 4 5 6 7 8 

Steps:

    1. Choose pivot. (it can be the first element or the last element)
    2. Partation Step: Place the pivot element at its correct position. 
                       i.e divide the array element on the bases of elements <=pivot & >pivot
       Divide ---|----->   <=Pivot
                 |----->    >Pivot
    3. Recursively sort the divided smaller parts
        quickSort(arr, start, pivot-1)
        quickSort(arr, pivot+1, end)


Explaination: 
    
    when, n=7, arr[] = {2,7,8,6,1,5,4}
    Now, partition(arr, 0, 6)

    when i=-1, j=0      |2|7|8|6|1|5|4|
         pivot = 6     i j           pivot
                      
         i=0, j=1       |2|7|8|6|1|5|4|       as a[j]<a[pivot], swap(arr[j], arr[i])
                         i j         pivot

         i=0, j=2       |2|7|8|6|1|5|4|
                         i   j       pivot

         i=0, j=3       |2|7|8|6|1|5|4|
                         i     j     pivot

         i=0, j=4       |2|7|8|6|1|5|4|       as a[j]<a[pivot], swap(arr[j], arr[i])
                         i       j   pivot

         i=1, j=5       |2|1|8|6|7|5|4|
                           i       j pivot

        As, j=6, exit loop

         i=1, j=6       |2|1|4|6|7|5|8|       swap(arr[i+1], arr[pivot])
         pivot=2           i pivot   j

        Now, return pivot index (i.e i+1)

*/
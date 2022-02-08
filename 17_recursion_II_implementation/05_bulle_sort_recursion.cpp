/*
    Topic - Bubble Sort Recursion

*/

#include <iostream>
using namespace std;


// Bubble Sort Recursively
void bubble_sort(int *arr, int size)
{
    // base case
    if (size == 1)
    {
        return;
    }
    // recursive case
    for (int j = 0; j < size - 1; j++)
    {
        // Take the largest element towards the end of array by pairwise swapping
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }
    // Make a recursice call on unsorted part of array
    return bubble_sort(arr, size - 1);

    /*
        APPROACH:
        - Take the largest element towards end of the array by pairwise swapping
        - Make a recursive call on unsorted part of array

        arr[] = 5 3 2 1       n = 4    where n = size of unsorted part of array
                3 2 1         n = 3
                2 1           n = 2
                1             n = 1
                So, return when length of unsorted part is 1.
    */
}


// Bubble Sort Completely Recursively
void bubble_sort_recursive(int *arr, int size, int j)
{
    // base case
    if (size == 1)
    {
        return;
    }
    if(j == size-1)
    {
        // when single pass of the current array has been done, 
        // then make a recursice call on unsorted part of array
        return bubble_sort_recursive(arr, size-1, 0);
    }
    // rec case
    if(arr[j]>arr[j+1])
    {
        swap(arr[j], arr[j+1]);
    }
    // when single pass of current array is not done, 
    // then increment index & take the largest element towards end of the array by pairwise swapping
    bubble_sort_recursive(arr, size, j+1);
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

    // bubble_sort(arr, size);
    bubble_sort_recursive(arr, size, 0);

    cout << "After Bubble Sort: ";
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
    After Bubble Sort: 1 2 3 4 5
 */
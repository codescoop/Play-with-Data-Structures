/* 
    Bubble Sort
    Take the largest element towards end! (Pairwise swapping)
 */
#include <iostream>
using namespace std;

// function to print array
void print_array(int arr[], int range){
    for (int index = 0; index < range; index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;
}

// bubble sort
void bubble_sort(int arr[], int range)
{   
    // iteration count
    for (int step = 1; step < range; step++)
    {   
        // iterating unsorted array
        for (int idx=0; idx < (range-step); idx++)    // [range-step] -> To decrease length of unsorted array from the end.
        {   
            // pairwise swapping
            if (arr[idx] > arr[idx + 1])   
            {
                swap(arr[idx], arr[idx + 1]);
            }
        }

        // print array 
        cout << "Step " << step << " : ";
        print_array(arr, range);
    }
}

// funtion to drive code
int main()
{
    int range;
    int arr[1000];

    cout << "How many elements you want to enter inside array: ";
    cin >> range;

    // Taking array values from user
    cout << "Enter the array elements for sorting: ";
    for (int index = 0; index < range; index++)
    {
        cin >> arr[index];
    }

    // Sorting array
    bubble_sort(arr, range);

    // print the sorted array
    cout << "Sorted Array: ";
    print_array(arr, range);

    return 0;
}

/* 
OUTPUT:

    How many elements you want to enter inside array: 5
    Enter the array elements for sorting: 5 1 4 3 2

    Step 1 : 1 4 3 2 5 
    Step 2 : 1 3 2 4 5 
    Step 3 : 1 2 3 4 5 
    Step 4 : 1 2 3 4 5 

    Sorted Array: 1 2 3 4 5 
*/
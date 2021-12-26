/* 
    Selection Sort
    Arrange a randomly shuffled array in increasing & descreasing order.
    
    The selection sort algorithm sorts an array by repeatedly finding the minimum element 
    from unsorted part and putting it at the beginning of unsorted array. 
    The algorithm maintains two subarrays in a given array.
    1) The subarray which is already sorted. 
    2) Remaining subarray which is unsorted.
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

// selection sort
void selection_sort(int arr[], int range)
{
    // loop for moving boundary of unsorted array
    for (int i=0; i <= range-2; i++)
    {
        // find out the smallest index in unsorted part
        int min_index = i;
        for (int j = i+1; j<=range-1; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        // We are only doing swap outside the loop because swap is a costly function.
        int temp = arr[i];
        arr[i] = arr[min_index];      // Swap first element with the min value
        arr[min_index] = temp;

        // print array 
        cout << "Step " << i+1 << " : ";
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
    for (int index = 0; index < range; index++){
        cin >> arr[index];
    }

    // Sorting array
    selection_sort(arr, range);

    // print the sorted array
    cout << "Sorted Array: ";
    print_array(arr, range);

    return 0;
}

/* 
OUTPUT: 
    How many elements you want to enter inside array: 5
    Enter the array elements for sorting: 5 1 4 3 2
 
    Step 1 : 1 5 4 3 2 
    Step 2 : 1 2 4 3 5 
    Step 3 : 1 2 3 4 5 
    Step 4 : 1 2 3 4 5 
 
    Sorted Array: 1 2 3 4 5 
*/
/* 
    Comparator - understanding the working
    - Add a comparator function in bubble sort method
    - Alter bubble sort function to accept function
 */

#include <iostream>
using namespace std;

bool compare(int val1, int val2){            // comparator function
    return val1 > val2;
}

void bubble_sort(int arr[], int range, bool (&cmp) (int val1, int val2))
{   
    // iteration count
    for (int itr = 1; itr < range; itr++)
    {   
        // iterating unsorted array
        for (int index = 0; index < range - itr; index++)
        {   
            // parewise swapping
            if (cmp(arr[index], arr[index + 1]))     // using compare function
            {
                swap(arr[index], arr[index + 1]);
            }
        }
    }
}

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
    bubble_sort(arr, range, compare);       // Function as Parameter

    // print the sorted array
    cout << "Sorted Array: ";
    for (int index = 0; index < range; index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;

    return 0;
}
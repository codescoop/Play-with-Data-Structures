/* 
    Selection Sort
    Arrange a randomly shuffled array in increasing & descreasing order.
*/

#include <iostream>
using namespace std;

void selection_sort(int arr[], int range)
{
    for (int i = 0; i < range - 1; i++)
    {
        // find out the smallest index in unsorted part
        int min_index = i;
        for (int j = i + 1; j < range; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        // We are only doing swap outside the loop because swap is a costly function.
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
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
    for (int index = 0; index < range; index++){
        cin >> arr[index];
    }

    // Sorting array
    selection_sort(arr, range);

    // print the sorted array
    cout << "Sorted Array: ";
    for (int index = 0; index < range; index++){
        cout << arr[index] << " ";
    }
    cout << endl;

    return 0;
}
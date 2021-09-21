/* 
    Insertion Sort
    Insert the "current" element in right position
*/

#include<iostream>
using namespace std;

void insertion_sort(int arr[], int range)
{   
    // iteration for sorted array
    for(int itr=1; itr<=range-1; itr++)
    {
        int curr = arr[itr];
        // placing "current" element on right position in sorted array
        int index = itr-1;
        while(arr[index]>curr and index>=0){
            arr[index+1] = arr[index];
            index--;
        }
        arr[index+1] = curr;
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
    insertion_sort(arr, range);

    // print the sorted array
    cout << "Sorted Array: ";
    for (int index = 0; index < range; index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;

    return 0;
}

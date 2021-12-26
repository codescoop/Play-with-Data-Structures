/* 
    Insertion Sort
    Insert the "current" element in right position

    The array is virtually split into a sorted and an unsorted part. 
    Values from the unsorted part are picked and placed at the correct position in the sorted part.
*/

#include<iostream>
using namespace std;

// function to print array
void print_array(int arr[], int range){
    for (int index = 0; index < range; index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;
}

// insertion sort
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

        // print array 
        cout << "Step " << itr << " : ";
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
    insertion_sort(arr, range);

    // print the sorted array
    cout << "Sorted Array: ";
    print_array(arr, range);

    return 0;
}

/*
OUTPUT:

    How many elements you want to enter inside array: 5
    Enter the array elements for sorting: 5 2 3 4 1

    Step 1 : 2 5 3 4 1 
    Step 2 : 2 3 5 4 1 
    Step 3 : 2 3 4 5 1 
    Step 4 : 1 2 3 4 5 
    
    Sorted Array: 1 2 3 4 5 
*/
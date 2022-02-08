/*
    Topic - Quick Sort

    - It is a inplace algorithm
    - Divide & Conquer
    - NlogN on avg case
    - N^2 on worst case (can be fixed using randomised quick sort )
*/

#include <iostream>
using namespace std;


// quick Sort
void quick_sort(int *arr, int start, int end)
{
    // code
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
    quick_sort(arr, 0, size-1);

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


 */
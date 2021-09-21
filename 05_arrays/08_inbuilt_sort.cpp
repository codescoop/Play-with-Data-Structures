/* 
    Inbuilt sort in C++ Standard Template Library

    - Sorting a array using sort() function of C++ STL is more effective than selection, bubble & insertion sort.
*/

#include<iostream>
#include<algorithm>
using namespace std;

//Define a comparator function
bool compare(int a, int b){
    return a > b;
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

    // Inbuit - Sorting function
    sort(arr, arr+range, compare);

    // print the sorted array
    cout << "Sorted Array: ";
    for (int index = 0; index < range; index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;

    return 0;
}

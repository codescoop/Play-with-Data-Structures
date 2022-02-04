/*
    Topic - Last Occurence / Linear Search

*/

#include <iostream>
using namespace std;

// find last occurence in linear search (recursion)
int lastOcc(int *arr, int size, int key)
{
    // base case
    if (size == 0)
    {
        return -1;
    }
    // rec case
    int idx = lastOcc(arr + 1, size - 1, key);         // recursive call

    if (idx == -1)                                     // check for search value
    {
        if (arr[0] == key)
        {
            // return the idx, when search value is found
            return 0;
        }
        else
        {
            // if search value is not found till now
            return -1;
        }
    }
    // if idx returned by subproblem is not -1, then increment the idx to update it according to current
    // array position
    return idx + 1;

    /*
        APPROACH:
        - first make a call on remaining part
        - then check KEY with current index
    */
}

// find first occurence in linear search (recursion)
int firstOcc(int arr[], int size, int key)
{
    // base case
    if (size == 0)
    {
        return -1;
    }
    // recursive case
    if (arr[0] == key)                             // check for search value
    {
        return 0;
    }
    int idx = firstOcc(arr + 1, size - 1, key);    // recursive call
    if (idx == -1)
    {
        return -1;
    }
    return idx + 1;

    /*
        APPROACH:
        - first check KEY with current index
        - then make a call on remaining part
    */
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

    int key;
    cout << "Enter Search Key: ";
    cin >> key;

    // first & last occurence in linear search
    cout << "first occurence : " << firstOcc(arr, size, key) << endl;
    cout << "last occurence  : " << lastOcc(arr, size, key) << endl;

    return 0;
}

/*
OUTPUT:

Case 1:
    Enter array size: 6
    Enter Elements: 1 2 7 3 7 6
    Enter Search Key: 7
    first occurence : 2
    last occurence  : 4

Case 2:
    Enter array size: 6
    Enter Elements: 1 2 17 3 17 6
    Enter Search Key: 7
    first occurence : -1
    last occurence  : -1
 */
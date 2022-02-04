/* 
    Topic - Recursion First Occurence / Linear Search

*/

#include <iostream>
using namespace std;

// functions to find first occurence in linear search (recursion)
int firstOcc(int arr[], int size, int key)
{
    // base case
    if(size == 0)
    {
        return -1;
    }
    // recursive case
    // check if first element is the search key return index
    if(arr[0] == key)
    {
        return 0;
    }
    // check if element is present in the pending array
    int idx = firstOcc(arr+1, size-1, key);
    // case if value not found in subproblem
    if(idx == -1)
    {
        return -1;
    }
    // case if search value is found in subproblem, then increment the idx returned from subproblem. As,
    // we want to update it according to current array position
    return idx+1;
}


// Approach 2: Converting iterative linear search FOR loop into recusive solution
int firstOcc2(int arr[], int i, int size, int key)
{
    // base case
    if(i==size)                            // stopping creteria of FOR loop 
    {
        return -1;
    }
    // rec case
    if(arr[i] == key)                       // condition in FOR loop
    {
        return i;
    }
    return firstOcc2(arr,i+1, size, key);   // update index
}


// function to drive code
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter Elements: ";
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter Search Key: ";
    cin >> key;


    // first occurence in linear search
    cout << "first occurence [Approach 1]: " << firstOcc(arr,size,key) << endl;
    cout << "first occurence [Approach 2]: " << firstOcc2(arr,0,size,key) << endl;

    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter array size: 9
    Enter Elements: 1 2 3 7 4 5 6 7 18
    Enter Search Key: 7
    first occurence [Approach 1]: 3
    first occurence [Approach 2]: 3

Case 2:
    Enter array size: 9
    Enter Elements: 1 2 3 7 4 5 6 7 18
    Enter Search Key: 9
    first occurence [Approach 1]: -1
    first occurence [Approach 2]: -1



Concept:
    - First check KEY with current index
    - then make a call on remaining part
 */
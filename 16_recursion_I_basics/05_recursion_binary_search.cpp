/* 
    Topic - Time to Try Recursion!

    Write a Recursive Functions to perform binary search.
    Eg:    arr = {1, 2, 3, 4, 5, 10, 20}
           key = 10
*/

#include <iostream>
using namespace std;


int binarySearch(int *a, int start, int end, int key)
{
    int mid = start + (end-start)/2;
    // base case
    if(start>end)
    {
        return -1;
    }
    // recursive case
    if(a[mid]==key)
    {
        return mid;
    }
    else if (key < a[mid])
    {
        return binarySearch(a, start, mid-1,key);
    }
    else
    {
        return binarySearch(a, mid+1, end,key);
    }
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

    // search for value
    int idx = binarySearch(arr,0 ,size-1, key);

    // display output
    if(idx >= 0){
        cout << "Value found at index: " << idx;
    }
    else{
        cout << "Value not found: ";
    }
    
    cout << endl;
    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter array size: 5
    Enter Elements: 1 3 4 5 15
    Enter Search Key: 5
    Value found at index: 3

Case 2:
    Enter array size: 5
    Enter Elements: 1 3 4 5 15
    Enter Search Key: 2
    Value not found

Case 3:
    Enter array size: 5
    Enter Elements: 1 3 4 5 15
    Enter Search Key: -10
    Value not found
 */
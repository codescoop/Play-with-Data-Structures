/*
    Topic - All Occurences Recursion / Linear Search

    - write a funtion to print all ocuurences
    - write a function to store all occurences (these type of concepts are used in other problems
                                                like subsequences, etc)
*/

#include <iostream>
using namespace std;

// store all occurence in linear search (recursion)
int storeOcc(int *arr, int idx, int size, int key, int *output, int j)
{
    // base case
    if(size == 0)
    {
        return j;
    }
    // recursive case
    if(arr[idx] == key)
    {
        output[j] = idx;
        j++;
    }
    return storeOcc(arr, idx+1, size-1, key, output, j);
}


// print all occurence in linear search (recursion)
void allOcc(int *arr, int idx, int size, int key)
{
    // base case
    if(size == 0)
    {
        return;
    }
    // rec case
    if(arr[idx] == key)                 // search & print value
    {
        cout << idx << ", ";
    }
    allOcc(arr, idx+1, size-1, key);      // recursive call
}


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
            return 0;
        }
        else
        {
            return -1;
        }
    }
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
    cout << "Enter array size : ";
    cin >> size;

    int arr[size];
    cout << "Enter Elements   : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter Search Key : ";
    cin >> key;

    cout << "First occurence  : " << firstOcc(arr, size, key) << endl;
    cout << "Last occurence   : " << lastOcc(arr, size, key) << endl;

    cout << "All occurences   : ";
    allOcc(arr, 0, size, key);

    cout << "\nStore occurences : "; 
    int output[size];
    int len = storeOcc(arr, 0, size, key, output, 0);

    for(int i=0; i<len; i++)
    {
        cout << output[i] << ", ";
    }

    cout << endl;
    return 0;
}

/*
OUTPUT:

Case 1:
    Enter array size : 7
    Enter Elements   : 1 2 7 3 7 7 9
    Enter Search Key : 7
    First occurence  : 2
    Last occurence   : 5
    All occurences   : 2, 4, 5, 
    Store occurences : 2, 4, 5, 

Case 2:
    Enter array size : 7
    Enter Elements   : 1 2 7 3 7 7 9
    Enter Search Key : 17
    First occurence  : -1
    Last occurence   : -1
    All occurences   : 
    Store occurences : 

Case 3:
    Enter array size : 7
    Enter Elements   : 1 2 7 3 7 7 9
    Enter Search Key : 3
    First occurence  : 3
    Last occurence   : 3
    All occurences   : 3, 
    Store occurences : 3, 
 */
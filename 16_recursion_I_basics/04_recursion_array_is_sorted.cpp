/* 
    Topic - Recursion Array is Sorted

    Write a recursive Functions to check if array is sorted
    {1, 2, 3, 4, 5, 10, 20}


    Easiest Way to Approach to Recursive Problems
    "Magical" Recursive Rule = Principle of Mathematical Induction (PMI)
    1. Figure out the Base Case
    2. Assume Sub Problem can be solved by recursion (automatically)
    3. Using the sub-problem write the answer for the current problem.

*/

#include <iostream>
using namespace std;

// function to check if array is sorted
bool isSorted(int *a, int size)
{
    // base case
    if(size==0 or size==1) 
    {
        return true;
    }
    // recursive case
    if(a[0]<a[1] && isSorted(a+1, size-1))
    {
        return true;
    }
    return false;
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

    cout << "Output: " << isSorted(arr, size);
    
    cout << endl;
    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter array size: 5
    Enter Elements: 1 2 3 14 5
    Output: 0

Case 2:
    Enter array size: 7     
    Enter Elements: 1 2 3 7 8 9 12
    Output: 1
 */
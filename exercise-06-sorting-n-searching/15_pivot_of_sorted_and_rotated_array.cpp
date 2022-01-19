/* 
    Problem - Pivot of Sorted and Rotated

    You are given a sorted but rotated array. You need to fine the index of the pivot element of the array
    where pivot is that element in the array which is greater than its next element and divides
    the array into two monotonically increasing halves.

    Input Format: The first line denotes N - the size of the array. 
                  The following N lines each denote the numbers in the array.

    Constraints:  Output Format
                  Output the index of the pivot of the array.

    Sample Input:   5
                    4 5 1 2 3

    Sample Output:  1

    Explanation:  Here, 5 is the pivot element. Thus the output is 1 which is 5's index.
*/

#include <iostream>
using namespace std;

// function to find index of pivot element (i.e largest element)
int get_pivot_index(int arr[], int size)
{
    int start = 0;
    int end = size-1;

    // Case when array is not rotated
    if(arr[start] < arr[end])
    { 
        return end;                // largest element
    }


    while(start<=end)
    {
        int mid = start + (end-start)/2;
        
        if(arr[mid] > arr[mid+1])
        {
            return mid;             // largest element
        }

        if(arr[mid] < arr[mid-1])
        {
            return mid-1;           // largest element
        }

        // check for sorted part & discard it. As pivot element lies in unsorted part
        if(arr[start] < arr[mid])
        {
            //first part is sorted so pivot element lies in second half
            start = mid+1;
        }
        else{
            // second part is sorted so pivot element lies in first half 
            end = mid-1;
        }
    }
    return -1;        // to avoid warning message
}


// function to drive code
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter array elements: ";
    for (int index = 0; index < size; index++)
    {
        cin >> arr[index];
    }

    // search index of pivot element
    int pivot_idx = get_pivot_index(arr,size);

    cout << "Pivot Index: ";
    cout << pivot_idx << endl;

    return 0;
}

/* 
OUTPUT:

Case 1:
    Enter array size: 6
    Enter array elements: 2 3 4 5 6 1
    Pivot Index: 4

Case 2:
    Enter array size: 6
    Enter array elements: 6 1 2 3 4 5
    Pivot Index: 0

Case 3:
    Enter array size: 6
    Enter array elements: 1 2 3 4 5 6
    Pivot Index: 5



Additional Info:

Ref: https://www.youtube.com/watch?v=Kcj2NGnuSNg
Ref: https://afteracademy.com/blog/minimum-in-a-sorted-and-rotated-array


Below are the Sample Case for a={1,2,3,4,5,6}

        lo  m     hi
Case1:  1 2 3 4 5 6      (not rotated)
Case2:  2 3 4 5 6 1      (corner case)
Case3:  3 4 5 6 1 2
Case4:  4 5 6 1 2 3
Case5:  5 6 1 2 3 4
Case6:  6 1 2 3 4 5      (corner case)


Another Solution :

Approach:

    If we look closely then you will find that there are at most three cases that could be encountered.

    Case 1: The leftmost value is less than the rightmost value in the array. 
            This means that the array is not rotated.
    Example: [1 2 3 4 5 6 7 8 9]

    Case 2:  The value in the middle of the array is greater than the leftmost and rightmost values
             in the array.
    Example: [4 5 6 7 8 9 1 2 3]

    Case 3 : The value in the middle of the array is less than the leftmost and rightmost values
             in the array.
    Example: [7 8 9 1 2 3 4 5 6]
    
    if we have case 1 then we just return the leftmost value in the array. 
    If we have case 2, we will try to find the minimum on the right side of the array. 
    If we have case 3, we will try to find the minimum to the left side of the array.

Solution steps

    1. Initialize a left and right variable with 0 and size-1 of the array.
    2. Iterate until left < right
        - If the value at left is less than the value at right then return value at left.
        - Initialize mid = (left + right )/ 2
        - Now compare if the value at mid is greater than the value at right, then we 
          search the minimum in the left part of the array. Update left = mid + 1
        - Otherwise, we search in the right part of the array. Update right = mid

CODE:
    int findMin(int array[], int size) 
    {
        int left = 0
        int right = size - 1
        while(left < right) 
        {
            if(array[left] < array[right])            // case 1
            return array[left]
            int mid = left + (right-left)/2
            if(array[mid] > array[right])
            left = mid + 1                            // case 2
            else
            right = mid                               // case 3
        }
    return array[left]
    }



Another Solutuon : (Recursive Approach)

    - Find middle point mid = (l + h)/2
    - If key is present at middle point, return mid.
    - Else If arr[l..mid] is sorted
        a) If key to be searched lies in range from arr[l] to arr[mid], recur for arr[l..mid].
        b) Else recur for arr[mid+1..r]
    - Else (arr[mid+1..r] must be sorted) .
        a) If key to be searched lies in range from arr[mid+1] to arr[r], recur for arr[mid+1..r].
        b) Else recur for arr[l..mid]


CODE:

    #include<iostream>
    using namespace std;

    int* getArray(int n){
        int *arr = new int[n];
        for(int i = 0; i < n;++i){
            cin>>arr[i];
        }
        return arr;
    }

    int findPivot(int *arr,int low,int high){
        if(low>high){
            return -1;
        }
        else
        if(low==high){
            return low;
        }
        int mid = (low + high)/2;
        if(mid < high && arr[mid] > arr[mid+1]){
            return mid;
        }
        if(mid > low && arr[mid] < arr[mid-1]){
            return mid-1;
        }
        if(arr[low] >= arr[mid]){
            return findPivot(arr,low,mid-1);
        }
        return findPivot(arr,mid+1,high);
    }

    int main() {
        int n;
        cin>>n;
        int *arr = getArray(n);
        int pivot = findPivot(arr,0,n-1);
        cout<<pivot<<endl;
        return 0;
    }
*/

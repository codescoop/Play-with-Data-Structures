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

// function to find index of pivot element
int get_pivot_index(int arr[], int size)
{
    int start = 0;
    int end = size-1;

    while(start<=end)
    {
        int mid = (start+end)/2;
        
        if(arr[mid] < arr[mid-1] && arr[mid] > arr[mid+1]){
            return mid;
        }
        // if first half of array is sorted
        else if(arr[start] < arr[mid]){
            start = mid+1;
        }
        // if second half of array is sorted
        else{
            end = mid-1;
        }
    }
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


Case 2:


APPROACH:


*/

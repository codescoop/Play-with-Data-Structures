/* 
    Problem - Help Aman to Search

    Aman has a sorted array of numbers from which he has to find a given 
    number quickly. His friend by mistake rotated the array. Now, Aman don't 
    have time to sort the elements again. 
    Help him to quickly find the given number from the rotated array.

    Hint - Think Binary Search!

    Input Format - First line contains N - the size of array.
                   The next N line contains the number of array
                   The next line contain the item to be searched

    Output Format - Output the  index of number in the array to be searched
                    Output -1 if number if not found
    
    Input - 5   
            4 5 1 2 3   
            2
    
    Output - 3

    Explanation: The given roatated array is [4,5,1,2,3].
                 The element to be searched is 2 whose index is 3.

    
*/

#include <iostream>
using namespace std;

// Search an element in a Sorted & Rotated Array
int sorted_rotated_search(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;

    while(start<=end)
    {
        int mid = (start+end)/2;
        
        if(arr[mid] == key)
        {
            return mid;
        }
        // Case1: When left part of array is sorted
        else if(arr[start] <=  arr[mid])
        {
            // If search value lies in left part of the mid.
            if(arr[start]<=key && arr[mid]>key){
                end = mid-1;
            }
            // If search value doesn't lies in left part of the mid.
            else{
                start = mid+1;
            }
        }
        // Case2: When right part of array is sorted
        else
        {
            // If search value lies in right part of the mid.
            if(arr[mid]<key && arr[end]>=key){
                start = mid+1;
            }
            // If search value doesn't lies in right part of the mid.
            else{
                end = mid-1;
            }
        }
    }
    return -1;
}

// function to drive code
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int arr[size];
    cout << "Enter sorted & rotated array: ";
    for (int index = 0; index < size; index++)
    {
        cin >> arr[index];
    }

    int key;
    cout << "Enter search key: ";
    cin >> key;

    // search in sorted & rotated array
    int idx = sorted_rotated_search(arr,size,key);

    if (idx == -1){
        cout << key << " is not present";
    }else{
        cout << key << ": found at index: " << idx;
    }

    cout << endl;    
    return 0;
}

/* 
OUTPUT:

Case1:
    Enter array size: 7
    Enter sorted & rotated array: 3 4 5 6 7 1 2
    Enter search key: 4
    4: found at index: 1

Case2:
    Enter array size: 7
    Enter sorted & rotated array: 6 7 1 2 3 4 5
    Enter search key: 4
    4: found at index: 5

Case3:
    Enter array size: 7
    Enter sorted & rotated array: 6 7 1 2 3 4 5
    Enter search key: 9
    9 is not present



APPROACH:

    Talking straightly, the Question is to find an element in the Sorted but Rotated array. 
    One can imagine this Question by finding the pivot element and then rotate it to get the original 
    array and can use Binary search to find the element but the main point to consider is that:-

    Finding the Pivot element in the array is of the O(n), so why would you do such a lot of work, 
    if it is so then you can also use Linear Search which will let you find the element in O(n), 
    Where n is the number of elements in the array.
    But You would get TLE as the constraint is quite large.

    Here is the Algorithm that will let you find the element in O(log n)
    1) Find middle point mid = (l + h)/2
    2) If the key is present at the middle point, return mid.
    3) Else If arr[l..mid] is sorted
        a) If the key to be searched lies in the range from arr[l] to 
            arr[mid], recur for arr[l..mid].
        b) Else recur for arr[mid+1..r]
    4) Else (arr[mid+1..r] must be sorted)
        a) If the key to be searched lies in the range from arr[mid+1]
            to arr[r], recur for arr[mid+1..r].
        b) Else recur for arr[l..mid] 


CODE:

    public static int search(int arr[], int l, int h, int key) {

        if (l > h)  
            return -1; 

        int mid = (l+h)/2; 
        if (arr[mid] == key) 
            return mid; 

        // If arr[l...mid] is sorted 
        if (arr[l] <= arr[mid]) { 

            if (key >= arr[l] && key <= arr[mid]) 
                return search(arr, l, mid-1, key); 

            return search(arr, mid+1, h, key); 
        } 

        if (key >= arr[mid] && key <= arr[h]) 
            return search(arr, mid+1, h, key); 

        return search(arr, l, mid-1, key); 
    }

*/

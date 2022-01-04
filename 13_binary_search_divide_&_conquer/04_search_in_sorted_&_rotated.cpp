/* 
    Topic - Search an element in a Sorted & Pivoted Array

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
#include <algorithm>
using namespace std;

// Search an element in a Sorted & Rotated Array
int findSearchValue(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid] == key){
            return mid;
        }
        // Case1: When left part of array is sorted
        else if(arr[start] <=  arr[mid]){
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
    int range, key;
    int arr[1000];

    cout << "Enter array size: ";
    cin >> range;

    cout << "Enter sorted & rotated array: ";
    for (int index = 0; index < range; index++){
        cin >> arr[index];
    }
    cout << "Enter search key: ";
    cin >> key;

    // search value
    int idx = findSearchValue(arr,range, key);

    if (idx == -1){
        cout << key << " is not present" << endl;
    }else{
        cout << key << ": found at index: " << idx << endl;
    }
    

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
*/
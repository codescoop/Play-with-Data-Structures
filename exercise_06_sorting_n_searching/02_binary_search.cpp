/* 
    Problem Name: Array-Binary Search
    
    Take a input N, the size of array. Take N more inputs and store that in an array. 
    Take a input  M. Write a function which returns the index on which M is found in the array, 
    in case M is not found -1 is returned. Print the value returned.
    You can assume that the array is sorted, but you’ve to optimize the finding process. For an array 
    of size 1024, you can make 10 comparisons at maximum.

    1.It reads a number N.
    2.Take Another N numbers as input in Ascending Order and store them in an Array.
    3.Take Another number M as input and find that number in Array.
    4.If the number M is found, index of M is returned else -1 is returned.Print the number returned.

    Input Format : Take a input N, the size of array. 
                   Take N more inputs and store that in an array.
                   Take a input M

    Constraints: N cannot be Negative. 
                 Range of Numbers N and M can be between -1000000000 to 1000000000

    Output Format: Print the value returned.

    Sample Input:   5
                    3
                    5
                    6
                    9
                    78
                    6
    
    Sample Output:  2
    
    Explanation: Array = {3, 5, 6, 9, 78}, target number = 6 . 
                 Index of number 6 in the given array = 2. 
                 Write Binary search to find the number in given array as discuss in the class.
*/

#include <iostream>
#include <algorithm>
#define ll long long int
using namespace  std;

ll binary_search(ll arr[], ll size, ll search_value)
{
    ll start = 0;
    ll end = size-1;

    while(start <= end)
    {
        ll mid = (start+end)/2;

        if(arr[mid] == search_value){
            return mid;
        }
        else if(arr[mid] < search_value){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
 }


// function to drive code
int main(){
    int testcases;
    cout << "Enter total testcases: ";
    cin >> testcases;

    while(testcases){
        ll size, search_value;

        cout << "Enter array size: ";
        cin >> size;
        
        ll arr[size];
        cout << "Enter array values: ";
        for(ll idx=0; idx<=size-1; idx++){
            cin >> arr[idx] ;
        }

        cout << "Enter search value: ";
        cin >> search_value;

        // finding maximum of minimum no of pages student can read
        ll idx = binary_search(arr, size, search_value);
        
        cout << "Index: ";
        cout << idx << endl;
        
        testcases--;
    }

    return 0;
}


/* 
OUTPUT:

    Enter total testcases: 1

    Enter array size: 5
    Enter array values: 3 5 6 9 78
    Enter search value: 6
    Index: 2

APPROACH:

    Binary Search: Search a sorted array by repeatedly dividing the search interval in half. 
                   Begin with an interval covering the whole array. If the value of the search key
                   is less than the item in the middle of the interval, narrow the interval to the
                   lower half. Otherwise narrow it to the upper half. 
                   Repeatedly check until the value is found or the interval is empty.

Algo:

    We basically ignore half of the elements just after one comparison.
    1. Compare item with the middle element.
    2. If item matches with middle element, we return the mid index.
    3. Else If item is greater than the mid element, then item can only lie in right half subarray after the mid element. So we search for right half.
    4. Else (item is smaller) search for the left half.

*/
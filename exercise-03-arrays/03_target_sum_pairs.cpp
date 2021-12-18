/*
    Array - Target Sum Pairs

    Take as input N, the size of array. 
    Take N more inputs and store that in an array. 
    Take as input “target”, a number. 
    Write a function which prints all pairs of numbers which sum to target.
    
    Input Format:  The first line contains input N. 
                   Next N lines contains the elements of array and (N+1)th line contains target number.

    Constraints:  Length of the arrays should be between 1 and 1000.
    
    Output Format: Print all the pairs of numbers which sum to target. Print each pair in increasing order.
    
    Sample Input:   5
                    1
                    3
                    4
                    2
                    5
                    5
    
    Sample Output:  1 and 4
                    2 and 3

    Explanation: Find any pair of elements in the array which has sum equal to target element and print them.

*/

#include <iostream>
#include <algorithm>
using namespace std;

void targetSum(int arr[], int range, int target){
    // sorting array
    sort(arr, arr+range);

    int start = 0;
    int end = range-1;
    while(start<end){
        int sum = arr[start] + arr[end];
        if(sum == target){
            cout << arr[start] << " and " << arr[end] << endl;
            start++;
            end--;
        }else if(sum < target){
            start++;
        }else{
            end--;
        }
    }
}

int main() {
	int range;
    cout << "Enter array range: ";
    cin >> range;

    int arr[range];
    cout << "Enter array elements: ";
    for(int idx=0; idx<=range-1; idx++){
        cin >> arr[idx];
    }

    int target;
    cout << "Enter Target value: ";
    cin >> target;

    cout << "All pairs of numbers which sum to target : \n";
    targetSum(arr, range, target);

	return 0;
}
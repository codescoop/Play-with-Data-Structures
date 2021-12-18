/*
    Array - Target Sum Triplets

    Take as input N, the size of array. 
    Take N more inputs and store that in an array. 
    Take as input “target”, a number. 
    Write a function which prints all triplets of numbers which sum to target.
    
    Input Format:  First line contains input N.
    Next line contains N space separated integers denoting the elements of the array.
    The third line contains a single integer T denoting the target element.

    Constraints:  Length of Array should be between 1 and 1000.
    
    Output Format: Print all the triplet present in the array in a new line each. 
    The triplets must be printed as A, B and C where A,B and C are the elements of the triplet ( A<=B<=C) and all triplets must be printed in sorted order. 
    Print only unique triplets.
    
    Sample Input:   9
                    5 7 9 1 2 4 6 8 3
                    10
    
    Sample Output:  1, 2 and 7
                    1, 3 and 6
                    1, 4 and 5
                    2, 3 and 5

    Explanation: Array = {5, 7, 9, 1, 2, 4, 6 ,8 ,3}. Target number = 10. 
                 Find any three number in the given array which sum to target number.

*/

#include <iostream>
#include <algorithm>
using namespace std;

void targetSum(int arr[], int range, int target){
    // sorting array
    sort(arr, arr+range);
    // finding triplets sum
    for (int step=0; step<=range-2; step++){
        int fixed = step;
        int start = fixed+1;
        int end = range-1;
        while(start<end){
            int sum = arr[fixed] + arr[start] + arr[end];
            if(sum == target){
                cout << arr[fixed] << ", " << arr[start] << " and " << arr[end] << endl;
                start++;
                end--;
            }else if(sum > target){
                end--;
            }else{
                start++;
            }
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

    cout << "All triplets of numbers which sum to target : \n";
    targetSum(arr, range, target);

	return 0;
}
/*
    Problem Name: Maximum length Bitonic Subarray

    You are provided n numbers of array. 
    You need to find the maximum length of bitonic subarray. 
    A subarray A[i … j] is bitonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.

    Input Format: First line contains integer t which is number of test case. 
                  For each test case, it contains an integer n which is the size of array and next line contains n space separated integers.
    
    Constraints: 1<=t<=100 
                 1<=n<=1000000

    Output Format: Print the maximum length.

    Sample Input:   2
                    6
                    12 4 78 90 45 23
                    4
                    40 30 20 10

    Sample Output:  5
                    4

    Explanation: ForMaximum length = 4, 78, 90, 45, 23
*/

#include <iostream>
using namespace std;


// function to check if array is bitonic or not
bool checkBitonic(int arr[], int start, int end){
    bool isIncreasing = true;
    for(int idx=start; idx<=end-1; idx++){
        if(arr[idx] == arr[idx+1]){
            return false;
        }else if(arr[idx] > arr[idx+1]){
            isIncreasing = false;
        }else if(arr[idx] < arr[idx+1] && !isIncreasing){
            return false;
        }
    }
    return true;
}

// Native Approach (Brute Force)
int maxBitonicArray(int arr[], int range){
    int maxLen = 0;
    bool isBitonic;
    for(int i=0; i<=range-1; i++){
        for(int j=i; j<=range-1; j++){
            int currLen = 0;
            int arrStart = i;
            int arrEnd = j;
            isBitonic = checkBitonic(arr, arrStart, arrEnd);
            if(isBitonic){
                currLen = arrEnd -arrStart;
                if(currLen > maxLen){
                    maxLen = currLen;
                }
            }
        }
    }
    return maxLen+1;     // adding 1 bcz start=0 instead of 1
}


int maxBitonicArray_optimized(int arr[], int range){
    int inc[range];
    int dec[range];
    int i, maxLen, currLen;

    inc[0] = 1;           // length of increasing sequence for first element
    dec[range-1] = 1;     // length of decreasing sequence for last element

    // Step 1: create increasing sequence array (i.e which stores Increasing value at each Index)
    for(i=1; i<=range-1; i++){
        inc[i] = (arr[i-1] <= arr[i] ? inc[i-1]+1 : 1); 
    }
    // Step 2: create decreasing sequence array
    for(i=range-2; i>=0; i--){
        dec[i] = (arr[i] >= arr[i+1] ? dec[i+1]+1 : 1);
    }
    // step 3: maximum length of bitonic seq = (inc[i]+dec[i]-1)
    // We subtract one since the current element at ith index is included in both the increasing and decreasing subarray lengths.
    maxLen =  inc[0]+dec[0]-1;      // for first element
    for(i=1; i<=range-1; i++){
        currLen = (inc[i]+dec[i]-1);
        if(currLen > maxLen){
            maxLen  =currLen;
        }
    }
    return maxLen;
}



// Drive code
int main() {
    int testCase;
    cout << "Total test cases: ";
    cin >> testCase;

    for (int idx=0; idx<=testCase-1; idx++){
        int range;
        cout << "Total no. of values: ";
        cin >> range;

        int arr[range];
        cout << "Enter values: ";
        for(int idx=0; idx<=range-1; idx++){
            cin >> arr[idx];
        }

        cout <<"Maximum length of Bitonic Subarray : ";
        // cout << maxBitonicArray(arr, range) << endl;
        cout << maxBitonicArray_optimized(arr, range) << endl;
    }

	return 0;
}

/* 
Problem Name : Maximum length Bitonic Subarray

Solution 
Let us consider the array {12, 4, 78, 90, 45, 23} to understand the solution. 
1) Construct an auxiliary array inc[] from left to right such that inc[i] contains length of the nondecreasing subarray ending at arr[i]. 
For A[] = {12, 4, 78, 90, 45, 23}, inc[] is {1, 1, 2, 3, 1, 1} 
2) Construct another array dec[] from right to left such that dec[i] contains length of nonincreasing subarray starting at arr[i]. 
For A[] = {12, 4, 78, 90, 45, 23}, dec[] is {2, 1, 1, 3, 2, 1}.
3) Once we have the inc[] and dec[] arrays, all we need to do is find the maximum value of (inc[i] + dec[i] – 1). 
For {12, 4, 78, 90, 45, 23}, the max value of (inc[i] + dec[i] – 1) is 5 for i = 3. 

Approach
We create two arrays - 'inc' and 'dec'
- inc[i] stores the length of increasing subarray till i.
- dec[i] stores the length of decreasing subarray starting from index i.
- Doing so gives us the length of increasing and decreasing subarray at each index in O(n) time.
- We calculate the length of the longest bitonic subarray by finding the maximum inc[i] + dec[i] - 1
- We subtract one since the current element at ith index is included in both the increasing and decreasing subarray lengths.


Algorithm
- Initialize inc[0] to 1 and dec[n-1] to 1
- Creating inc[] array
a. Till end of the array ie, i=1 to n, if arr[i] > arr[i-1] then inc[i] = inc[i-1] + 1. else, inc[i] = 1
- Creating dec[] array
a. From the end of the array ie, i = n-2 till i =0, if arr[i] > arr[i+1] then dec[i] = dec[i+1] +1 else, dec[i] = 1


Java Code
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int t=scn.nextInt();
        while(t-- > 0) {
        int n = scn.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scn.nextInt();
        }
        System.out.println(bitonic(arr));
        }
    }

    public static int bitonic(int arr[]) 
    { 
        int n=arr.length;
        int[] inc = new int[n]; 

        int[] dec = new int[n]; 
        int max; 

        inc[0] = 1; 
        dec[n-1] = 1; 
        for (int i = 1; i < n; i++) 
           inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1; 
        for (int i = n-2; i >= 0; i--) 
            dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1; 
        max = inc[0] + dec[0] - 1; 
        for (int i = 1; i < n; i++) 
            if (inc[i] + dec[i] - 1 > max) 
                max = inc[i] + dec[i] - 1; 

        return max; 
    } 

}


C++ Code

int bitonic(int arr[], int n)
{
    int inc[n]; // Length of increasing subarray ending at all indexes
    int dec[n]; // Length of decreasing subarray starting at all indexes
    int i, max;

    // length of increasing sequence ending at first index is 1
    inc[0] = 1;

    // length of increasing sequence starting at first index is 1
    dec[n-1] = 1;

    // Step 1) Construct increasing sequence array
    for (i = 1; i < n; i++)
    inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;

    // Step 2) Construct decreasing sequence array
    for (i = n-2; i >= 0; i--)
    dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;

    // Step 3) Find the length of maximum length bitonic sequence
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;

    return max;
}
*/
/*
    Problem Name: Maximum Circular Sum

    You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. 
    You need to find the maximum sum of consecutive numbers.

    Input Format: First line contains integer t which is number of test case.
                  For each test case, it contains an integer n which is the size of array and next line contains n space separated integers denoting the elements of the array.

    Constraints: 1<=t<=100
                 1<=n<=1000
                 |Ai| <= 10000

    Output Format: Print the maximum circular sum for each testcase in a new line.

    Sample Input:   1
                    7
                    8 -8 9 -9 10 -11 12

    Sample Output:  22

    Explanation: Maximum Circular Sum = 22 (12 + 8 - 8 + 9 - 9 + 10)
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Subarray Sum using Kadane Algo
int maxSubarraySum(int arr[], int range){
    int maxSum = 0;
    int currentSum = 0;
    for(int itr=0; itr<=range-1; itr++){
        currentSum += arr[itr];
        if(currentSum < 0){
            currentSum = 0;
        }
        if(currentSum > maxSum){
            maxSum = currentSum;
        }
    }
    return maxSum;
}

// Native Approach (Brute Force)
int maxCircularSum(int arr[], int range){
    int maxVal = 0;
    for(int idx=0; idx<=range-1; idx++){
        // finding max value
        for(int j=0; j<=range-1; j++){
            int currentMax = maxSubarraySum(arr, range);
            
            if(currentMax > maxVal){
                maxVal = currentMax;
            }
        }
        // rotate array
        int temp = arr[0];
        int i;
        for (i=0; i<=range-2; i++){
            arr[i] = arr[i+1];
        }
        arr[i] = temp;
    }
    return maxVal;
}

// Better Approach
int maxCircularSum_optimized(int arr[], int range){
    int maxSum = 0;
    for(int idx=0; idx<=range-1; idx++){
        int currentSum = 0;
        // first half (i to n)
        for(int j=idx; j<=range-1; j++){
            currentSum += arr[j];
            if(currentSum < 0){
                currentSum = 0;
            }
            if(currentSum > maxSum){
                maxSum = currentSum;
            }
        }
        // second half (0 to i)
        for(int j=0; j<idx; j++){
            currentSum += arr[j];
            if(currentSum < 0){
                currentSum = 0;
            }
            if(currentSum > maxSum){
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}

// Best Approach
int maxCircularSum_optimized2(int arr[], int range){
    // case 1: Max Sum when no wrapping is involved
    int maxNoWrap = maxSubarraySum(arr, range);

    // case 2: Max Sum when wrapping is involved (i.e include corner case)
    int maxWrap = 0;
    int idx;
    for(idx=0; idx<=range-1; idx++){
        maxWrap += arr[idx];         // calculate array sum
        arr[idx] = -arr[idx];        // invert the sign of array element
    }
    // max sum of corner elements =  (array sum - (- max subarray sum of inverted array))
    int nonContibSum = maxSubarraySum(arr,range);
    maxWrap = maxWrap + nonContibSum;

    // Maximum Sum will be max of two sums from case1 & case2
    return (maxWrap > maxNoWrap ? maxWrap : maxNoWrap);
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

        cout <<"Max Contiguous sum in Circulr Array : ";
        // cout << maxCircularSum(arr, range) << endl;
        // cout << maxCircularSum_optimized(arr, range) << endl;
        cout << maxCircularSum_optimized2(arr, range) << endl;
    }

	return 0;
}

/* 
    This Question can be done using the brute force viz, by using two nested loops and checking the sum of every possible subset but this approach is in O(n^2). So, Now we are going to discuss an approach which solves the given problem in O(n).

    Approach :
    For finding the Maximum Contiguous sum we are using the kadane's algorithm. But in the question the array is circular that means the maximum sum can be of elements which are a part of the wrapping or not. So,
    There can be two cases for the maximum sum:
    Case 1: The elements that contribute to the maximum sum are arranged such that no wrapping is there. Examples: {-10, 2, -1, 5}, {-2, 4, -1, 4, -1}. In this case, Kadane’s algorithm will produce the result.

    Case 2: The elements which contribute to the maximum sum are arranged such that wrapping is there. Examples: {10, -12, 11}, {12, -5, 4, -8, 11}. In this case, we change wrapping to non-wrapping. Let us see how. Wrapping of contributing elements implies non wrapping of non contributing elements, so find out the sum of non contributing elements and subtract this sum from the total sum. To find out the sum of non contributing, invert sign of each element and then run Kadane’s algorithm. Our array is like a ring and we have to eliminate the maximum continuous negative that implies maximum continuous positive in the inverted arrays.

    Java Solution

    public class maxCircularSum{
        public static void main(String[] args){

        Scanner scn = new Scanner(System.in);

        int t = new nextInt();

        while(t > 0){

            int n = scn.nextInt();

            int[] arr = new int[n];

            for(int i =0;i < n;i++)
                arr[i] = scn.nextInt();

            System.out.println(maxSum(arr));

            t--;
        }
    }

    public static int maxSum(int[] arr){

        int max_kadane = kadanes(arr);

        int max_wrap = 0;

        for(int i =0;i < arr.length;i++){
            max_wrap += arr[i];
            arr[i] = -arr[i];
        }

        int non_contib_sum = kadanes(arr);
        max_wrap = max_wrap + non_contib_sum;

        return (max_wrap > max_kadane?max_wrap:max_kadane);

    }

        public static int kadanes(int[] A) {

            int max_so_far = 0;
            int max_ending_here = 0;


            for(int i = 0;i < A.length;i++){

                max_ending_here += A[i];

                if(max_ending_here < 0){
                    max_ending_here = 0;
                }

                if(max_so_far < max_ending_here){
                    max_so_far = max_ending_here;
                }
            }
            return max_so_far;
        }
    }

    -----------------------------------------
    C++ Solution 

    #include<bits/stdc++.h>
    using namespace std;

    // Standard Kadane's algorithm to find maximum subarray sum
    int kadane(int a[], int n)
    {
        int max_so_far = 0, max_ending_here = 0;
        int i;
        for (i = 0; i < n; i++)
        {
            max_ending_here = max_ending_here + a[i];
            if (max_ending_here < 0)
                max_ending_here = 0;
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
        }
        return max_so_far;
    }

    // The function returns maximum circular contiguous sum in a[]
    int maxCircularSum(int a[], int n)
    {
        // Case 1: get the maximum sum using standard kadane's algorithm
        int max_kadane = kadane(a, n);

        // Case 2: Now find the maximum sum that includes corner elements.
        int max_wrap = 0, i;
        for (i=0; i<n; i++)
        {
                max_wrap += a[i];         // Calculate array-sum
                a[i] = -a[i];             // invert the array (change sign)
        }

        // max sum with corner elements will be:    array-sum - (-max subarray sum of inverted array)
        int non_contib_sum = kadane(a,n);
        max_wrap = max_wrap + non_contib_sum;

        // The maximum circular sum will be maximum of two sums
        return (max_wrap > max_kadane)? max_wrap: max_kadane;
    }

    
    // Driver program
    int main()
    {
        int t;
        cin>>t;
        for(int i=0;i<t;i++)
        {
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
            cout<< maxCircularSum(a, n) <<endl;
        }
        return 0;
    }

*/
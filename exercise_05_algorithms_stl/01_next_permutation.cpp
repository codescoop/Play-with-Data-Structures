/*
    Problem Name: Next Permutation

    Given an array Arr[], Treat each element of the array as the digit and whole array as the number. 
    Implement the next permutation, which rearranges numbers into the numerically next greater 
    permutation of numbers.

    If such arrangement is not possible, it must be rearranged as the lowest possible order ie, 
    sorted in an ascending order.

    Note: The replacement must be in-place, do not allocate extra memory.


    Input Format: The First Line contains the Number of test cases T.
                  Next Line contains an Integer N, number of digits of the number.
                  Next Line contains N-space separated integers which are elements of the array 'Arr'.

    Constraints: 1 <= T <= 100
                 1 <= N <= 1000
                 0 <= A[i] <= 9

    Output Format: Print the Next Permutation for each number separated by a new Line.


    Sample Input:   2
                    3
                    1 2 3 
                    3
                    3 2 1

    Sample Output:  1 3 2
                    1 2 3

    Explanation: Possible permutations for {1,2,3} are {1,2,3} , {1,3,2} , {2,1,3} , {2,3,1}, 
                 {3,1,2} and {3,2,1}. 
                 {1,3,2} is the immediate next permutation after {1,2,3}.
                 For the second testcase , {3,2,1} is the last configuration so we print the 
                 first permutation as its next permutation.
*/

#include <iostream>
using namespace std;

// function to print array
void print_array(int arr[], int size){
    for(int idx=0; idx<=size-1; ++idx){
        cout << arr[idx] << " ";
    }
    cout << endl;
}

// function to reverse array elements
void reverse(int arr[], int left, int size){
    int right = size-1;
    while(left < (right)){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}


// function to find smallest next permutation greater than previous one.
void get_next_permutation(int arr[], int size){
    int smaller_idx = 0;          // to store smaller index
    int greater_idx = 0;          // to store greater index

    // [Right to Left] find first element that is less than previous one .
    for(int i=size-2; i>=0; --i){
        if(arr[i] < arr[i+1]){
            smaller_idx = i;
            break;
        }
    }
    // [Right to Left] find value that is greater_idx than "smaller_idx" value.
    for(int i=size-1; i>=smaller_idx; i--){
        if(arr[i] > arr[smaller_idx]){
            greater_idx = i;
            break;
        }
    }
    // If it's the largest sequence
    if(smaller_idx == 0 && greater_idx == 0){
        reverse(arr,0,size);
        return;
    }

    // swap values
    swap(arr[smaller_idx], arr[greater_idx]);
    
    //reverse array elements which are after smaller_idx
    if(smaller_idx < size-1){
        reverse(arr, smaller_idx+1, size);
    }
    
}

// function to drive code
int main() {
    int testcase;
    cout << "Enter total Testcases: ";
    cin >> testcase;

    for(int i=0; i<=testcase-1; i++){
        int size;
        cout << "Enter Array Size: ";
        cin >> size;

        int *arr = new int[size];
        // take input
        cout << "Enter Elements: ";
        for(int idx=0; idx<=size-1; idx++){
            cin >> arr[idx];
        }

        // print next permutations
        cout << "Next Permutations: ";
        get_next_permutation(arr, size);

        print_array(arr, size);

    }

	return 0;
}

/* 

Algorithm: 

    - Scan from right to left, find the first element that is less than its previous one.
        4 5 6 3 2 1 
        |
        p

    - Scan from right to left, find the first element that is greater than p.
        4 5 6 3 2 1 
            |
            q

    - Swap p and q
        4 5 6 3 2 1 
        swap
        4 6 5 3 2 1 

    - Reverse elements [p+1, nums.length]
        4 6 1 2 3 5 

    
Required Code is given below :

    #include <bits/stdc++.h>
    using namespace std;


    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }


    void next_permutation(vector<int> &nums) {

        if (nums.size() < 2)
            return;

        int p = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                p = i;
                break;
            }
        }

        int q = 0;
        for (int i = nums.size() - 1; i > p; i--) {
            if (nums[i] > nums[p]) {
                q = i;
                break;
            }
        }

        if (p == 0 && q == 0) {
            reverse(nums, 0, nums.size() - 1);
            return;
        }

        swap(nums[p], nums[q]);

        if (p < nums.size() - 1) {
            reverse(nums, p + 1, nums.size() - 1);
        }
    }



    int main() {
        int testCases;
        cin >> testCases;
        while (testCases--) {
            int n;
            cin >> n;
            vector<int> v(n);
            for (int i = 0; i < n; ++i) {
                cin >> v[i];
            }

            next_permutation(v);

            for (int x : v) {
                cout << x << " ";
            }
            cout << endl;
        }

        return 0;
    }

*/

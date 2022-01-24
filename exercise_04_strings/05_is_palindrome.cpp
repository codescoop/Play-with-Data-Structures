/*
    Problem Name: Is Palindrome?

    Take as input N, a number. 
    Take N more inputs and store that in an array. 
    Write a RECURSIVE function which tests if the array is a palindrome and returns a Boolean value. Print the value returned.

    Input Format: Enter a number N , add N more numbers

    Constraints: NONE

    Output Format: Display the Boolean result

    Sample Input: 4
                  1
                  2
                  2
                  1

    Sample Output: true

    Explanation: NA

*/

#include <iostream>
using namespace std;

bool isPalindrome(int arr[], int range){
    int start = 0;
    int end = range-1;
    while(start < end){
        if(arr[start] != arr[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool isPalindromeRecursive(int arr[], int end, int start=0 ){     // default value of start=0 if value not assigned
    // if string is empty return false
    if (end == 0){
        return false;
    }
    // if length of string is one, then it is palindrome
    if(end == 1){
        return true;
    }
    // if start is greater than end return true
    if(start > end-1){
        return true;
    }
    // check first and last character
    if(arr[start] != arr[end-1]){
        return false;
    }else{
        return isPalindromeRecursive(arr, --end, ++start);      // recursive call
    }
}

int main(){
    int range;
    cout << "Enter total numbers: ";
    cin >> range;

    int arr[range];
    for(int idx=0; idx<=range-1; idx++){
        cin >> arr[idx];
    }

    // bool status = isPalindrome(arr, range);        // two pointer approach
    bool status = isPalindromeRecursive(arr, range);           // recursive call

    if(status){
        cout << "true";
    }else{
        cout << "false";
    }
    cout << endl;
	return 0;
}

/* 
Approach:

    Loop over the array and compare the element from left end of the array with 
    the corresponding element from the right end of the array. 
    At any point, if the elements do not match, terminate the loop. 
    If the whole loop completed, then the array is palindrome.

Code:
    public boolean isPalindrome(int[] array) {
        int length = array.length;
        
        for (int index = 0; index < array.length; index++) {
            // get the element from the start
            int start = array[index];
     
            // get corresponding element from end
            int end = array[--length];
     
            // check if elements till the middle have been compared
            if (length < index) {
                return true;
            }
     
            // if start element is not the same as end element, the array is not palindrome
            if (start != end) {
                return false;
            }
        }
        // if the control reaches here, means all the elements were same 
    return true;
}

*/
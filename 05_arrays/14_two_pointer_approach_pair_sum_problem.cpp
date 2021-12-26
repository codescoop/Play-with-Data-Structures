/*  
    Pair Sum Problem (Two Pointer Approach)

    >> Given a sorted array, Find pair of elements that sum to k(Given)
 */

#include <iostream>
using namespace std;

int main(){
    // int arr[] = {1,3,5,7,10,11,12,13};
    int arr[] = {1,3,4,5,7,10,11,12,13};      // Remember array must be sorted
    int k=16;

    int i = 0;                                  // "i" is pointing at array beginning
    int j = (sizeof(arr)/sizeof(int))-1;        // "j" is pointing at last
    
    while(i<j){
        int currentSum = arr[i]+arr[j];
        if(currentSum == k){
            cout << arr[i] << " and " << arr[j] << endl;
            i++;
            j--;
        }else if(currentSum > k){
            j--;
        }else{
            i++;
        }
    }

    return 0;
}

/* 

OUTPUT: 3 and 13
        4 and 12
        5 and 11
*/
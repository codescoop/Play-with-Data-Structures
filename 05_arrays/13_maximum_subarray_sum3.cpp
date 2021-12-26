/*  
    Largest/maxmimum subarrays sum III 
    (Kadane's Algorithm) - 1 loop

    Eg: Array        : -4  1  3 -2  6  2 -1 -4 -7
        Current Sum  :  0  1  4  2  8 10  9  5  0
        Max Sum      :  0  1  4  4  8 10 10 10 10
 */

#include <iostream>
using namespace std;

void subarrays(int arr[], int range){
    int currentSum = 0;
    int maxSum = 0;
    
    // Using Kadane's Algorithm
    for(int i=0; i<range; i++){
        currentSum += arr[i];      
        if(currentSum < 0){        
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }

    // print the maximum sum
    cout << "Maximun Sum: " << maxSum << endl;
}


int main(){
    int arr[100], range;
    cout << "Enter total elements: ";
    cin >> range;
    
    cout << "Enter values: ";
    for(int itr=0; itr<range; itr++){
        cin>>arr[itr];
    }

    subarrays(arr, range);

    return 0;
}

/* 
OUTPUT:
    Enter total elements: 9
    Enter values: -4 1 3 -2 6 2 -1 -4 -7
    Maximun Sum: 10
*/
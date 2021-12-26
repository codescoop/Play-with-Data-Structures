/*  
    Largest/maxmimum subarrays sum I
    (using brute force) - 3 Nesting loop
 */

#include <iostream>
using namespace std;

void subarrays(int arr[], int range){
    int maxSum = 0;
    int left = -1;             // for storing maximum subarray left index
    int right = -1;            // for storing maximum  subarray right index

    for(int start=0; start<range; start++){
        for(int end=start; end<range; end++){
            
            // Element of subarrays(start,end)
            int currentSum = 0;

            for(int k=start; k<=end; k++){
                currentSum += arr[k];
            }
            // Updating maximum sum if currentSum  > maximumSum
            if(currentSum > maxSum){
                maxSum = currentSum;
                left = start;
                right = end;
            }
        }
    }
    // print the maximum sum
    cout << "Maximun Sum: " << maxSum << endl;
    
    // print the subarray
    cout << "Subarray having Maximum Sum: ";
    for(int k=left; k<=right; k++){
        cout << arr[k] << ",";
    }
    cout << endl;
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
    Subarray having Maximum Sum: 1,3,-2,6,2,
*/
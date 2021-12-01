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

    for(int i=0; i<range; i++){
        for(int j=i; j<range; j++){
            
            // Element of subarrays(i,j)
            int currentSum = 0;

            for(int k=i; k<=j; k++){
                currentSum += arr[k];
            }
            // Updating maximum sum if currentSum  > maximumSum
            if(currentSum > maxSum){
                maxSum = currentSum;
                left = i;
                right = j;
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
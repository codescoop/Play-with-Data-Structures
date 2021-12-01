/*  
    Largest/maxmimum subarrays sum II 
    (using cumulative sum) - 2 Nesting loop
 */

#include <iostream>
using namespace std;

void subarrays(int arr[], int range, int csum[]){
    int maxSum = 0;
    int left = -1;             // for storing maximum subarray left index
    int right = -1;            // for storing maximum  subarray right index

    for(int i=0; i<range; i++){
        for(int j=i; j<range; j++){
            
            // Element of subarrays(i,j)
            int currentSum = 0;
            
            // calculating sum using cumulative array
            currentSum = csum[j] - csum[i-1];    

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
    int csum[100] = {0};              // array for cumulative sum
    cout << "Enter total elements: ";
    cin >> range;

    
    cout << "Enter values: ";
    cin>>arr[0];
    csum[0] = arr[0];                            // first value of cumulative array
    for(int itr=1; itr<range; itr++){
        cin>>arr[itr];
        csum[itr] = csum[itr-1] + arr[itr];       // creating cumulative sum array
    }

    subarrays(arr, range, csum);

    return 0;
}
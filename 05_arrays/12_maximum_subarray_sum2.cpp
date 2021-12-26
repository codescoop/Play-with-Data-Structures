/*  
    Largest/maxmimum subarrays sum II 
    (using cumulative sum) - 2 Nesting loop

    Eg:     Array           : -4  1  3 -2  6  2 -1 -4 -7
            Cumulative Sum  : -4 -3  0 -2  4  6  5  1 -6

            Array           : -4  1  3 -2  6  2 -1 -4 -7
                                  |        |
            Subarray        :    START     END
s
    FORMULA:  sum_of_subarray[START,END] = cumulative_sum[END] - cumulative_sum[START-1]
 */

#include <iostream>
using namespace std;

void subarrays(int arr[], int range, int csum[]){
    int maxSum = 0;
    int left = -1;             // for storing maximum subarray left index
    int right = -1;            // for storing maximum  subarray right index

    for(int start=0; start<range; start++){
        for(int end=start; end<range; end++){
            
            // Element of subarrays(start,end)
            int currentSum = 0;
            
            // calculating sum using cumulative array
            currentSum = csum[end] - csum[start-1];    

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
    int csum[100] = {0};              // array for cumulative sum
    cout << "Enter total elements: ";
    cin >> range;

    
    cout << "Enter values: ";
    cin>>arr[0];
    csum[0] = arr[0];                            // first value of cumulative array
    for(int itr=1; itr<=range-1; itr++){
        cin>>arr[itr];
        csum[itr] = csum[itr-1] + arr[itr];       // creating cumulative sum array
    }

    // print cumulative subarray
    cout << "Cumulative Subarray: ";
    for(int itr=0; itr<=range-1; itr++){
        cout << csum[itr] << " "; 
    }
    cout << endl;

    subarrays(arr, range, csum);

    return 0;
}

/* 
OUTPUT:
    Enter total elements: 9
    Enter values:        -4 1 3 -2 6 2 -1 -4 -7
    Cumulative Subarray: -4 -3 0 -2 4 6 5 1 -6 

    Maximun Sum: 10
    Subarray having Maximum Sum: 1,3,-2,6,2,
*/
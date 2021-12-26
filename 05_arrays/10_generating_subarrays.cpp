/* 
    Generating Subarrays
    >> Given a aray, print all the subarrays
 */

#include <iostream>
using namespace std;

void subarrays(int arr[], int range){
    cout << "Subarrays :- \n";
    // Generating all subarays
    for(int start=0; start<range; start++){        // For subarray start values
        for(int end=start; end<range; end++){      // For subarray end values
            // Elements of subarrays(start,end)
            for(int k=start; k<=end; k++){         // Loop array-values to generate subarray
                cout << arr[k] << ",";  
            }
            cout << endl;
        }
    }
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
    Enter total elements: 5
    
    Enter values: 1 2 3 4 5
    
    Subarrays :- 
    1,
    1,2,
    1,2,3,
    1,2,3,4,
    1,2,3,4,5,
    2,
    2,3,
    2,3,4,
    2,3,4,5,
    3,
    3,4,
    3,4,5,
    4,
    4,5,
    5,
*/
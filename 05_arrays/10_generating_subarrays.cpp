/* 
    Generating Subarrays
    >> Given a aray, print all the subarrays
 */

#include <iostream>
using namespace std;

void subarrays(int arr[], int range){
    cout << "Subarrays :- \n";
    // Generating all subarays
    for(int i=0; i<range; i++){
        for(int j=i; j<range; j++){
            // Elements of subarrays(i,j)
            for(int k=i; k<=j; k++){
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
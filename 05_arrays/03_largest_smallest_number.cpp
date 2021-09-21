/* 
    Find the Largest & Smallest number in array.
*/

#include<iostream>
#include<climits>
using namespace std;

int main(){
    int range;
    cout << "How many elements you want to enter: ";
    cin >> range;

    int arr[100];
    cout << "Enter array elements: ";
    for(int index=0; index<range; index++){
        cin >> arr[index];
    }

    int smallest = INT_MAX;
    int largest = INT_MIN;

    for(int index=0; index<range; index++){
        if(arr[index]>largest){
            largest = arr[index];
        }
        if(arr[index]<smallest){
            smallest = arr[index];
        }
    }
    
    cout  << "Smallest: " << smallest << endl;
    cout << "Largest: " << largest << endl;
    return 0; 
}

/* 
    without if loop :-
    
    for(int index=0; index<num; index++){
        largest = max(largest, arr[index]);
        smallest = min(smallest, arr[index]);
    }
 */
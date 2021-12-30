/* 
    Topic - Binary Search STL
   
    We will cover:
    - binary search function (return boolean value)
    - lower bound function   (return address)
    - upper bound function   (return address)

    Note: For the above functions, array must be sorted
    
*/

#include <iostream>
#include <algorithm>
using namespace  std;

void print_array(int arr[], int size){
    for(int idx=0; idx<=size-1; ++idx){
        cout << arr[idx] << " ";
    }
    cout << endl;
}

int main(){
    // Search in a sorted array
    int arr[] = {20,30,40,40,40,50,60,100};
    int size = sizeof(arr)/sizeof(int);
    int key = 56;
    
    cout << "Array: ";
    print_array(arr, size);

    // binary search
    bool status = binary_search(arr, arr+size, key);
    if(status){
        cout << key <<  " is present" << endl;
    }else{
        cout << key << " is not present" << endl;
    }
    
    // lower bound
    auto lb = lower_bound(arr, arr+size, key);
    int lb_index = lb - arr;
    cout << key << ": lower bound index: " << lb_index << endl;
    
    /* NOTE: If search value is not present in array. Then, lower bound 
             will return address of value, greater than the search value */
    
    // upper bound
    auto ub = upper_bound(arr, arr+size, key);
    int ub_index = ub - arr;
    cout << key << ": upper bound index: " << ub_index << endl;


    // finding the occurance frequency of search key
    int freq = ub - lb;                    // upper_bound_address - lower_bound_address
    // int freq = ub_index - lb_index;     // upper_bound_index - lower_bound_index
    cout << "Total occurance: " << freq << endl; 

    return 0;
}

/* 

OUTPUT: 

case 1:[when key=40]
        
        Array: 20 30 40 40 40 50 60 100 
        40 is present
        40: lower bound index: 2
        40: upper bound index: 5
        Total occurance: 3

case 2:[when key=50]
        
        Array: 20 30 40 40 40 50 60 100
        50 is present
        50: lower bound index: 5
        50: upper bound index: 6
        Total occurance: 1

case 3:[when key=51]
        
        Array: 20 30 40 40 40 50 60 100
        51 is not present
        51: lower bound index: 6
        51: upper bound index: 6
        Total occurance: 0
*/
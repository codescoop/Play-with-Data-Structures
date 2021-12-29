/* 
    Topic - Find Function
   
    return value : An iterator to the first element in the range that compares equal
                   to val. If no elements match, the function returns last.
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
    int arr[] = {1,10,11,9,100};
    int size = sizeof(arr)/sizeof(int);
    int key = 11;

    cout << "Array: ";
    print_array(arr, size);
    
    // Search using find()
    auto it = find(arr, arr+size, key);
    cout << "Address: " << it << endl;

    int index = it - arr;           
    /* subtracting two pointers to get the number of elements between the two pointers. */

    if(index == size){
        cout << key << " not present";
    }else{
        cout << key << " present at index: " << index;
    }
  
    cout << endl;
    return 0;
}

/* 
OUTPUT: 

case 1:[when key=11]

        Array: 1 10 11 9 100 
        Address: 0x7ffcc7a2c7d8
        11 present at index: 2

case2: [when key=110]

        Array: 1 10 11 9 100 
        Address: 0x7ffd05db8d44
        110 not present

*/
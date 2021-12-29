/* 
    Topic: Some Common Methods (STL)
    
    We will cover:
    - swap()
    - max()
    - min()
    - reverse()

*/

#include<iostream>
#include<algorithm>
using namespace std;

void print_array(int arr[], int size){
    for(int idx=0; idx<=size-1; ++idx){
        cout << arr[idx] << " ";
    }
    cout << endl;
}


int main()
{
    int a = 10;
    int b = 20;
    cout << "a: " << a << "| b: " << b << "\n\n";

    // swap
    cout << "After swap: " << endl;
    swap(a,b);
    cout << "a: " << a << "| b: " << b << endl;


    // min & max
    cout << "mix: " << min(a,b) << endl;
    cout << "max: " << max(a,b) << "\n\n";


    // reverve first 4 element of array
    int arr[] = {10,20,30,40,50};
    int size = sizeof(arr)/sizeof(int);

    cout << "Array: ";
    print_array(arr,size);

    reverse(arr, arr+4);
    
    cout << "Reverved first 4 element: ";
    print_array(arr,size);
    cout << endl;

    return 0;
}

/* 
OUTPUT: 

    a: 10| b: 20

    After swap: 
    a: 20| b: 10
    
    mix: 10
    max: 20

    Array: 10 20 30 40 50 
    Reverved first 4 element: 40 30 20 10 50 
*/
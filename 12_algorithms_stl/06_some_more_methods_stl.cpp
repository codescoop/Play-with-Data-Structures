/* 
    Topic: Some More Methods (STL)

    We will cover:
    - swap()
    - max()
    - min()
    - reverse()
    - max_element()
    - min_element()

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


    // min_element
    auto min_ptr = min_element(arr, arr+size); 
    /* It return a pointer to the smallest element in the range, and 
       in case if there are more than one such element,then it points to the first one.
       It points to the last in case the range is empty.*/
    cout << "Minimum Element: " << *min_ptr << endl;;


    // max_element:
    auto max_ptr = max_element(arr, arr+size);
    /* It returns a pointer to the largest element in the range, and 
       in case if there are more than  one such element, then it points to the first one.
       It points to the last in case the range is empty. */
    cout << "Maximum Element: " << *max_ptr << endl;;
    
    // NOTE: both min_element() & max_element() accepts comparator function
    
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
    Minimum Element: 10
    Maximum Element: 50
*/
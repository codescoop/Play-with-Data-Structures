/* 
    Array basics
*/

#include <iostream>
using namespace std;

int main()
{   
    // create array
    int arr[] = {9, 55};               // array declaration & initilizations
    cout << "Elements in array: " << sizeof(arr)/sizeof(int) << endl;


    // create array
    int arr1[10];                       // array declaration
    int arr2[10] = {5};                 // array declaration & initilizations

    // size of array
    cout << "Size of array: " << sizeof(arr1) << endl;
    int arr_total_elements = sizeof(arr1) / sizeof(int);
    cout << "Total elements in array: " << arr_total_elements << endl;

    // Adding 5 elements in array by user
    cout << "Enter 5 elements in array: ";
    for(int index = 0 ; index < 5; index++){
        cin >> arr1[index];
    }

    // update a single index
    arr2[5] = 56;

    // print array
    for(int index = 0 ; index < arr_total_elements; index++){
        cout << arr1[index] << " ";     // arr1 with remaining values as garbage values
    }
    cout << endl;
    for(int index = 0 ; index < arr_total_elements; index++){
        cout << arr2[index] << " ";     // arr2 with remaining values as zeros
    }
    cout << endl;


    return 0;
}
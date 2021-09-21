/* 
    Linear Search Algorithm
*/

#include<iostream>
using namespace std;

int main(){
    int range, key;
    int arr[1000];

    cout << "How many elements you want to enter in array: ";
    cin >> range;

    cout << "Enter array elements: ";
    for (int  index=0; index<range; index++){
        cin >> arr[index];
    }
    //Ask for the element we want to search
    cout << "Enter the key you want to search: ";
    cin >> key;

    // Find out the index of that element by traversing the array
    // Linear Search Algorithm
    int index;
    for(index=0; index<range; index++){
        if(arr[index]==key){
            cout << key << " is present at index: " << index << endl;
            break;
        }
    }
    if(index == range)
        cout << key << " is not present." <<endl;
    return 0;
}

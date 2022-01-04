/* 
    Topic - Binary Search - First & Last Occurence
*/

#include <iostream>
using namespace std;

int first_occurence(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int first_idx = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(key == arr[mid]){
            first_idx = mid;
            end = mid-1;
        }else if(key < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return first_idx;
}

int last_occurence(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int last_idx = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(key == arr[mid]){
            last_idx = mid;
            start = mid+1;
        }else if(key < arr[mid]){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return last_idx;
}

int main()
{
    int range, key;
    int arr[1000];

    cout << "Enter array size: ";
    cin >> range;

    cout << "Enter array elements [sorted order]: ";
    for (int index = 0; index < range; index++){
        cin >> arr[index];
    }
    //Asking for search value
    cout << "Enter search key: ";
    cin >> key;

    // first occurence
    int first_idx = first_occurence(arr, range, key);
    // last occurence
    int last_idx = last_occurence(arr, range, key);
    
    if (first_idx == -1){
        cout << key << " is not present" << endl;
    }else{
        cout << "key-" << key << ": first occurence at: " << first_idx << endl;
        cout << "key-" << key << ": last occurence at: " << last_idx << endl;
    }
    return 0;
}

/* 
OUTPUT:
    
    Case 1:
        Enter array size: 11
        Enter array elements [sorted order]: 1 2 2 2 3 4 6 7 9 9 9
        Enter search key: 9
        key-9: first occurence at: 8
        key-9: last occurence at: 10
    
    Case 2:
        Enter array size: 6
        Enter array elements [sorted order]: 1 2 3 3 3 6
        Enter search key: 4
        4 is not present
*/
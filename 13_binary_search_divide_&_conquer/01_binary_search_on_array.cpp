/* 
    Topic - Binary Search on Array

    - Effective way to search in sorted array.
*/

#include <iostream>
using namespace std;

int binary_search(int arr[], int range, int key)
{
    int start = 0;
    int end = range;

    while (start <= end)
    {
        // calculating the middle value
        int mid = (start + end) / 2;  

        if (arr[mid] == key){
            return mid;
        }
        else if (arr[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
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

    // searching the value
    int index = binary_search(arr, range, key);

    if (index == -1){
        cout << key << " is not present" << endl;
    }else{
        cout << key << " is present at index: " << index << endl;
    }
    return 0;
}

/* 
OUTPUT:
    
    Case 1:
        Enter array size: 6
        Enter array elements [sorted order]: 11 28 39 45 69 97
        Enter search key: 39
        39 is present at index: 2
    
    Case 2:
        Enter array size: 6
        Enter array elements [sorted order]: 5 25 48 53 78 82
        Enter search key: 50
        50 is not present
*/
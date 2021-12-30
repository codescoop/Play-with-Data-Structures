/* 
    Binary Search
    Effective way to search in sorted array.
*/

#include <iostream>
using namespace std;

int binary_search(int arr[], int range, int key)
{
    int start = 0;
    int end = range;

    while (start <= end)
    {
        int mid = (start + end) / 2;  // calculating the middle value

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;                   
}

int main()
{
    int range, key;
    int arr[1000];

    cout << "How many elements you want to enter inside array: ";
    cin >> range;

    cout << "Enter the array elemets in sorted order: ";
    for (int index = 0; index < range; index++){
        cin >> arr[index];
    }
    //Ask for the element we want to search
    cout << "Enter the value to search: ";
    cin >> key;

    int index = binary_search(arr, range, key);       // searching the value

    if (index == -1){
        cout << key << " is not present" << endl;
    }else{
        cout << key << " is present at " << index << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int binary_search(int a[], int size, int key)
{
    int low = 0;
    int high = size;
    int mid;
    while (low <= high)
    {
        mid = (low+high)/2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}

int main()
{
    int size, index;
    cout<<"Enter the Array size : ";
    cin>>size;

    int a[size];
    cout<<"Enter values for sorted array : ";
    for (int i = 0; i < size; i++) cin>> a[i];

    cout<<"Array : ";
    for (int i = 0; i < size; i++) cout<<a[i]<<" ";

    int search_value;
    cout<<"\nEnter the value to search : ";
    cin>>search_value;

    index = binary_search(a, size, search_value);
    if (index == -1)
        cout<<"Search is not in array";
    else
        cout<<"Search value at Index : "<<index;

    return 0;
}

/*
Input:  Enter the Array size : 7
        Enter values for sorted array : 9
        15
        26
        37
        39
        52
        89
        Array : 9 15 26 37 39 52 89
        Enter the value to search : 52

Output: Search value at Index : 5
*/
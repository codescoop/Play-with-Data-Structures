#include <iostream>
using namespace std;

// Function to print array elements
void display(int arr[],int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

//Function to left rotate array
void leftrotate(int arr[], int size)
{
    int i = 0;
    int temp = arr[i];

    for (i=0; i<size;i++)
        arr[i]=arr[i+1];
    arr[size-1] = temp;
}

int main()
{
    int size, i, rotation;
    
    cout << "Enter the array size : ";
    cin >> size;

    int arr[size] = {0};    
    cout << "Enter array values : ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Array Elements : ";
    display(arr,size);

    cout << "\nEnter number of rotation : ";
    cin>>rotation;

    for (i=0; i<rotation;i++)
        leftrotate(arr,size);  // Function calling 
    
    cout << "\nRotated Array : ";
    display(arr,size);

    return 0;
}

/*
Input:  Enter the array size : 5
        Enter array values : 10
        20
        30
        40
        50
        Array Elements : 10 20 30 40 50
        Enter number of rotation : 2

Output: Rotated Array : 30 40 50 10 20
*/
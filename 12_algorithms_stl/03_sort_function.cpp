/* 
    Topic - Sort Function
   
    - Sorting a array using sort() function of C++ STL is more effective than 
      selection, bubble & insertion sort.
*/

#include<iostream>
#include<algorithm>
using namespace std;

//define a comparator function
bool compare(int a, int b){
    return a > b;
}

int main()
{
    int range;
    int arr[1000];

    cout << "Enter array size: ";
    cin >> range;

    // Taking array values from user
    cout << "Enter array elements: ";
    for (int index = 0; index < range; index++)
    {
        cin >> arr[index];
    }

    // Inbuit - Sorting function
    sort(arr, arr+range, compare);

    // print the sorted array
    cout << "Sorted Array: ";
    for (int index = 0; index < range; index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;

    return 0;
}

/* 
OUTPUT: 

    Enter array size      : 5
    Enter array elements  : 1 6 2 5 4
    Sorted Array          : 6 5 4 2 1 

*/
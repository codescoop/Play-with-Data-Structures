/*
    Topic - DNF Sort [Sort an array of 0s, 1s and 2s]

    Given an array A[] consisting 0s, 1s and 2s. The task is to write a function that sorts the given array.
    The functions should put all 0s first, then all 1s and all 2s in last.
    
    Examples:   Input: {0, 1, 2, 0, 1, 2}
                Output: {0, 0, 1, 1, 2, 2}
            
                Input: {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1}
                Output: {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2}

    Note: we can sort the above array using sorting algorithms like counting sort & more.
          But, by using DNF sort, we can sort the array in a single iteration, as well as inplace.
*/

#include <iostream>
using namespace std;

// sort an array of 0s, 1s and 2s [inplace & using single iteration]
void dnf_sort(int arr[], int size)
{
    int lo = 0;             // low pointer
    int hi = size-1;        // high pointer
    int curr = 0;           // current pointer

    while(curr <= hi)
    {
        if(arr[curr] == 0)
        {
            swap(arr[curr], arr[lo]);
            lo++;
            curr++;
        }
        else if(arr[curr] == 1)
        {
            curr++;
        }
        else
            swap(arr[curr], arr[hi]);
            hi--;
            /* Note: we will not increment curr pointer (i.e curr++) because we are not sure that arr[hi] is
                     always having a value 2. It can also have value 0 or 1, So we have to again check arr[curr]
                     in the next iteration.
            */
                     
        {

        }
    }
}


// function to drive code
int main()
{
    int arr[] = {2,1,1,1,1,0,1,1,1,0,0,2,0};
    int size = sizeof(arr)/sizeof(int);

    cout << "Array: ";
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }

    dnf_sort(arr, size);

    cout << "\nAfter Sorting: ";
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}


/*
OUTPUT:

    Array: 2 1 1 1s 1 0 1 1 1 0 0 2 0 
    After Sorting: 0 0 1 1 1 1 1 1 1 0 0 2 2 

*/
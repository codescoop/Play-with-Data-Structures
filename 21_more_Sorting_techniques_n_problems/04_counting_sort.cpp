/* 
    Topic - Counting Sort

    Counting sort is a sorting algorithm that sorts the elements of an array by counting the number of 
    occurrences of each unique element in the array.
    The count is stored in an auxiliary array and the sorting is done by mapping the count as an 
    index of the auxiliary array.


    Eg: Sample Input:  6
                       2 2 1 6 6 3

       Sample Output:  1 2 2 3 6 6
*/

#include <iostream>
using namespace  std;

void counting_sort(int arr[], int size)
{
    // find largest number in the array
    int largest_num = -1;
	for (int i = 0; i < size; i++) 
    {
		largest_num = max(largest_num, arr[i]);
	}

  // create & update frequency array tillthe largest number
    int *freq = new int[largest_num+1]{0};
    
    for(int i=0; i<size; i++)
    {
        freq[arr[i]]++;
    }

    // Update array with sorted values by reading frequency array
    int j = 0;
    for(int i=0; i<=largest_num; i++)
    {
        while(freq[i] > 0)
        {
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
}


int main() 
{
	int size;
	cout << "Enter array size: ";
    cin >> size;

	int arr[size];
    cout << "Enter array elements: ";
	for (int i = 0; i < size; i++) 
    {
		cin >> arr[i];
	}

    counting_sort(arr, size);

    cout << "Sorted Array: ";
	for (int i = 0; i < size; i++) 
    {
		cout << arr[i] << " ";
	}

    cout << endl;
	return 0;
}

       
/* 
OUTPUT:

Case 1:
    Enter array size: 6
    Enter array elements: 2 2 1 6 6 3
    Sorted Array: 1 2 2 3 6 6

Case 2:
    Enter array size: 9
    Enter array elements: 1 3 2 8 7 8 6 1 5
    Sorted Array: 1 1 2 3 5 6 7 8 8 

*/
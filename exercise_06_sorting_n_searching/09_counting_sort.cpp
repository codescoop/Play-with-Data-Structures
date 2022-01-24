/* 
    Topic - Counting Sort

    You are given an array, A. Sort this array using counting sort algorithm.

    Input Format: First line contains a single integer, n, denoting the size of the array. 
                  Next line contains n integers, denoting the elements of the array.

    Constraints: 1<=N<=10^6 
                 0<=Ai<=10^6

    Output Format:  Print the array in sorted order.

    Sample Input:   5
                    1 3 2 6 5

    Sample Output:  1 2 3 5 6
*/

#include <iostream>
using namespace  std;

int main() 
{
	int size;
	cout << "Enter array size: ";
    cin >> size;

	int arr[size];
	int maxNum=0;
    cout << "Enter array elements: ";
	for (int i = 0; i < size; i++) 
    {
		cin >> arr[i];
		if(arr[i]>maxNum)
        {
			maxNum=arr[i];
		}
	}

	int freq[maxNum+1] = {0};
	for (int i = 0; i < size; i++) 
    {
		freq[arr[i]]++;
	}

    cout << "Sorted Array: ";
	for (int i = 0; i < maxNum+1; i++) 
    {
		if(freq[i]!=0)
        {
			while(freq[i]--)
            {
				cout << i<<" ";
			}
		}
	}

    cout << endl;
	return 0;
}

       
/* 
OUTPUT:

Case 1:
    Enter array size: 5
    Enter array elements: 5 2 1 4 3
    Sorted Array: 1 2 3 4 5s


APPROACH:

    In this problem, we do not use comparisons instead we use a frequency array to sort the array. 
    This can be done using first calculating the frequency of each element that occurs in the array 
    and then printing an element till its frequency is greater than zero. 
    The size of the frequency array will be the max-min+1, where max and min are the maximum and 
    minimum of the array respectively. For every occurring element e, increase frequency at 
    index e by 1. For an array with negative elements also, we consider the size as max-min+1 where
    minimum has its absolute values considered. The index 0 of the frequency array will now represent
    the minimum value of the array. So we can store the values on the correct index by considering 
    that index=element-min. While again printing the original value in the sorted array is by saying 
    that the value is index+min value as it was altered while storing on the correct index. 
    
    1) Take a count array to store the count of each unique object. 
    2) Modify the count array such that each element at each index stores the sum of previous counts.
       The modified count array indicates the position of each object in the output sequence. 
    3) Output each object from the input sequence followed by decreasing its count by 1. 
    
    Time and Space Complexities: 
    
    - The time complexity of the algorithm is O(n+k), 
      where n is the number of elements and k is the range of input.
    - The space complexity is also the same. 
      Since a frequency is needed to store the frequency.

*/
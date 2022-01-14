/* 
    Topic - Sorting in Linear Time
    
    You will be given an array containing only 0s, 1s and 2s. you have sort the array in linear time 
    that is O(N) where N is the size of the array.

    Input Format: The first line contains N, which is the size of the array. 
                  The following N lines contain either 0, or 1, or 2.

    Constraints:    1 <= N <= 10^6
                    Each input element x, such that x ∈ { 0, 1, 2 }.

    Output Format:  Output the sorted array with each element separated by a newline.

    Sample Input:   5
                    0
                    1
                    2
                    1
                    2

    Sample Output:  0
                    1
                    1
                    2
                    2
*/

#include <iostream>
using namespace  std;

int main(){
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    int arr[size];
    cout << "Enter array elements[Only 0,1 & 2]: ";
    for(int idx=0; idx<=size-1; idx++){
        cin >> arr[idx] ;
    }
    
    // dividing array into three regions for zero, one and two
    int low = 0;             // pointer for 1st section
    int mid = 0;             // pointer for 2nd section
    int high = size-1;       // pointer for 3rd section

    // sorting array using 3 pointers
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else{
            // when arr[mid] == 2
            swap(arr[high], arr[mid]);
            high--;
        }
    }

    // print sorted array
    cout << "Sorted Array: ";
    for(int idx=0; idx<=size-1; idx++){
        cout << arr[idx] << " " ;
    }
    cout << endl;

    return 0;
}
       

/* 
OUTPUT:

Case 1:
    Enter array size: 5
    Enter array elements[Only 0,1 & 2]: 2 1 0 1 2
    Sorted Array: 0 1 1 2 2 

Case2: 
    Enter array size: 7 
    Enter array elements[Only 0,1 & 2]: 0 2 2 1 2 0 1
    Sorted Array: 0 0 1 1 2 2 2 



APPROACH:
    For the question the approach to be followed is to define regions of zero, one and two as there 
    are only these three elements in the array. 
    The region 1 will be of zero as it the least among the three then the region for 1 and in the end 
    the third region of 2’s.

Logic

    In this question there will be three regions defined for three different elements. 
    A pointer that keeps a track of where the region for 1 starts and a pointer for where the region 
    for 2 starts. Since 2 is to be placed in the end so the region for two starts in the end and 
    the pointer for 2 decreases as we place a new two. 
    If current element is zero then place it with the pointer where 1 starts and increase the pointer 
    by 1 as zero’s region is expanded.

    1. itr=0, ptr1=0, ptr2=array size -1
    2. Repeat the steps 3 , 4 and 5 for itr<=ptr2
    3. If array[itr] is 0 then swap element at ptr1 with itr and increase ptr1 and itr
    4. If array[itr] is 1 then just increase the itr
    5. Else the element is 2 , so swap the element at itr and ptr2 and decrease ptr by 1 
    
    Time Complexity:- The time complexity of this array is O(n) or linear time complexity. 
                      This is an in-place linear algorithm to sort elements.

Code: 
    void swap(int *a, int *b) 
    { 
        int temp = *a; 
        *a = *b; 
        *b = temp; 
    } 
    
    void sort_012(int a[], int arr_size) 
    { 
        int lo = 0; 
        int hi = arr_size - 1; 
        int mid = 0; 

        while (mid <= hi) 
        { 
            switch (a[mid]) 
            { 
            case 0: 
                swap(&a[lo++], &a[mid++]); 
                break; 
            case 1: 
                mid++; 
                break; 
            case 2: 
                swap(&a[mid], &a[hi--]); 
                break; 
            } 
        } 
    } 


*/
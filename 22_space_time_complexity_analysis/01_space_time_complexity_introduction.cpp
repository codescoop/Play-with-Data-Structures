/*
    Space Time Complexity - Introduction

    - Order Complexity of Algorithms
      1. Time Complexity  - Time Complexity is amount of time taken by the algorithm to run as a 
                            function of the input size
      2. Space Complexity - Space complexity of an algorithm quantifies the amount of space or memory 
                            taken by an algorithm to run as a function of the length of the input.

    NOTE: If there is trade off between Space & Time. Then, mostly the preference is given to Time.
      
    Also, we will be doing the analysis as a function of input.
           time  -> f(N)              // time is a function of input size
           space -> f(N)              // space is a function of input size
         
    Complexity Notation: [Big-oh, Omega & Theta]
        1. Big Oh Notation defines an upper bound of an algorithm, it bounds a function only from above.
        2. Omega Notation defines an lower bound of an algorithm i.e provides an asymptotic lower bound.
        3. Theta Notation bounds a functions from above and below, so it defines exact asymptotic behavior.

        NOTE: when we sure of one single value then we express complexity of function in Theta Notations. 
              But, if we are NOT sure of one single value then we express it using Big-O & Omega Notations.

    Complexity Cases Analysis: [Best, Worst & Average]
        Various types of Time Complexities Case which can be analyzed for the algorithm:
        1. Best case time complesity: Calculating lower bound on running time of an algorithm and is 
           the time taken in the case that causes minimum number of operations to be executed.
        2. Worst case time Complexity: Calculating upper bound on running time of an algorithm and is 
           the time taken in the case that causes maximum number of operations to be executed.
        3. Average Time complexity Algorithm: In average case analysis, we take all possible inputs and 
           calculate computing time for all of the inputs. Sum all the calculated values and divide 
           the sum by total number of inputs.
           Average case = ___All_Possible_case_time____
                                  No. of Cases
           As, in average case, we have to compute time for all of the inputs. So mostly we don't calculate avg. time 

    Note: DON'T relate Upper Bound(Big-Oh) with best Case, or Lower Bound(Omega) with worst Case or
                Theta with the Average Case beacuse they are NOT Related with each other.

          Complexity "Case" & "Notations" are not related to each other.
          As, Notation are for the functions 
              where as
              Case are just type of analysis done on the algorithms.
          So, All "Cases" like best, worst & average can be written or expressed using any "Notations" [Big-O, Omega or Theta]

          Eg: For linear Search:  Best Case time - B(n) = 1          Worst Case time - W(n) = n  
                                                   B(n) = O(1)                         W(n) = Big O(1)    
                                                   B(n) = Omega(1)                     W(n) = Omega(1)
                                                   B(n) = Theta(1)                     W(n) = Theta(1)
                   

    Order of Growth:  
    1 < logn < sqrt(n) < n < nlogn < n^2 < n^2logn < n^3 < ... < 2^n < 3^n < ... < n^n

    Note: n^n  grows faster than n!. 
          Below is illustrated by just considering the first couple of numbers:-
           ________________ _____________
          |____n^n_________|____n!_______|
          |    1^1 = 1     |    1!=1     |
          |    2^2 = 4     |    2!=2     |
          |    3^3 = 27    |    3!=6     |
          |    4^4 = 256   |    4!=24    |
          |    5^5 = 3125  |    5!=120   |
          |____..._________|____...______|
         
         So, range of n!:   1 < n! < n^n
     ________________ __________ ______________________________________________
    |                |          |___________Value_of_N_------->________________|
    |  Description   | Function |  1   |  10   |  100    |  1000     |   ...   |
    |________________|__________|______|_______|_________|___________|_________|
    |                |          |      |       |         |           |         |
    |  constant      |    1     |  1   |  1    |  1      |  1        |   ...   |   Good
    |  logarithmic   |   logN   |  0   |  1    |  2      |  3        |   ...   |   Good
    |  linear        |    N     |  1   |  10   |  100    |  1000     |   ...   |   Fair
    |  linearithmic  |   NlogN  |  0   |  10   |  200    |  3000     |   ...   |   Bad
    |  quadratic     |    N^2   |  1   |  100  |  10,000 |  1,00,000 |   ...   |   Horrible
    |  cubic         |    N^3   |  1   |  10^3 |  100^3  |  1000^3   |   ...   |   Horrible
    |  exponential   |    2^N   |  2   |  2^10 |  2^100  |  2^1000   |   ...   |   Horrible
    |  factorial     |    N!    |  1   | 3.6E+6| 9.3E+157| 4.02E+2567|   ...   |   Horrible
    |  ..            |          |      |       |         |           |   ...   |   Horrible
    |________________|__________|______|_______|_________|___________|_________|

    Excellent : **
    Good      : 1, logN
    Fair      : N
    Bad       : NlogN
    Horrible  : N^2, N^3, N^N

    NOTE: Logarithmic are convient way to express large numbers.
          The base-10 logarithmic of a number is roughly the number of digits in the number.


                                        Big-O Complexity Chart
     _______________ ______ ___________ ________ ___________ __________ ________ _____ ________ _____
    |               |      |           |        |           |          |        |     |        |      |
    | Input Size(n) | O(1) | O(log(n)) | O(n)   | O(n*logn) |  O(n^2)  | O(n^3) | ... | O(2^n) | O(n!)|
    |_______________|______|___________|________|___________|__________|________|_____|________|___ __|
    |               |      |           |        |           |          |        |     |        |      |
    |      1        |  1   |     1     |    1   |     1     |      1   |  ...   | ... |  ...   | ...  |
    |      4        |  1   |     2     |    4   |     8     |     16   |  ...   | ... |  ...   | ...  |
    |     16        |  1   |     4     |   16   |    64     |    256   |  ...   | ... |  ...   | ...  |
    |    1024       |  1   |    10     |  1024  |   10240   |  1048576 |  ...   | ... |  ...   | ...  |
    |     ...       | ...  |   ...     |   ...  |    ...    |    ...   |  ...   | ... |  ...   | ...  |
    |_______________|______|___________|________|___________|__________|________|_____|________|___ __|

    
    How to do analysis?
    - Practical Approach  : Run each and every algoirithm & then decide which one is better. 
                            NOTE: it may be infeasible to code all the algorithm & then check the complexity
                            as it will waste a lot of time.
    - Theoretical Approach : Judge the complexity of algorithm before we write the code. [Mostly Preferred]

*/


// Compare & Analysing the time complexity of Bubble Sort & Merge Sort [Using Practical Appraoch]
#include <iostream>
// #include <algorithm>
#include <ctime>
using namespace std;


// bubble sort
void bubble_sort(int arr[], int range)
{   
    // iteration count
    for (int step = 1; step < range; step++)
    {   
        // iterating unsorted array
        for (int idx=0; idx < (range-step); idx++)    // [range-step] -> To decrease length of unsorted array from the end.
        {   
            // pairwise swapping
            if (arr[idx] > arr[idx + 1])   
            {
                swap(arr[idx], arr[idx + 1]);
            }
        }
    }
}


// function to merge two subarrays using 2-pointers approach
void merge(int *arr, int start, int mid, int end)
{
    int i = start;              // pointer for left subarray
    int j = mid + 1;            // pointer for right subarray
    int k = start;              // pointer for temp array 

    int temp[start + end + 1];  // create temp array to store merged values

    // Merge the two subarrays back into temp array in sorted order
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    // Merge the remaining elements of left subarray, if there are any
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    // Merge the remaining elements of right subarray, if there are any
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    // Copy all elements of temp array into original array
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }
}


// Merge Sort
void merge_sort(int *arr, int start, int end)
{
    // base case: for 0 or 1 elements
    if (start >= end)
    {
        return;
    }

    // rec case
    int mid = start + (end - start) / 2;

    // Divide: recursively divide the array in two halves - [start,mid] & [mid+1,end], until base case i.e sorted
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);

    // Merge the two sorted halves
    merge(arr, start, mid, end);
    return;
}


// function to print array
void print_array(int arr[], int range){
    for (int i = 0; i < range; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// funtion to drive code
int main()
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    // Create Reverse Sorted array
    int a1[size], a2[size];
    for (int i = size-1; i >= 0; i--)
    {
        a1[i] = a2[i] = i;
    }

    // // Display Array
    // cout << "Array: ";
    // print_array(a1, size);


    time_t start, end;

    start = clock();
    bubble_sort(a1, size);
    end = clock();
    cout << "Time Taken [Bubble Sort]: " << end-start << " ms" << endl;

    start = clock();
    // sort(a2, a2+size);
    merge_sort(a2, 0, size-1);
    end = clock();
    cout << "Time Taken [Merge Sort]:  " << end-start << " ms" << endl;

    // // print the sorted array
    // cout << "Bubble Sort [Array]: ";
    // print_array(a1, size);
    // cout << "Merge Sort [Array]: ";
    // print_array(a2, size);

    return 0;
}


/* 
OUTPUT:

Case1:
    Enter array size: 100
    Time Taken [Bubble Sort]: 96 ms
    Time Taken [Merge Sort] : 41 ms

Case2:
    Enter array size: 1000
    Time Taken [Bubble Sort]: 4979 ms
    Time Taken [Merge Sort] : 233 ms

Case3:
    Enter array size: 10000
    Time Taken [Bubble Sort]: 217074 ms
    Time Taken [Merge Sort] : 2289 ms

Case4:
    Enter array size: 100000
    Time Taken [Bubble Sort]: 22233906 ms
    Time Taken [Merge Sort]: 16798 ms


Comparison & Time Complexity: 
     ___________ ____________________________
    |  (Input)  |______(Time_taken_---->)____|
    |_____N_____|__Bubble_Sort_|__Merge_Sort_|
    |           |              |             |
    |    100    |      96      |      41     |
    |   1000    |     4979     |     233     |
    |   10000   |    217074    |    2289     |
    |  100000   |   22233906   |   16798     |
    |___________|______________|_____________|

So, Time Coxplexity:  O(N^2)       O(NLogN)   


Reference:-

Abdul bari - https://www.youtube.com/watch?v=A03oI0znAoc [Asymptotic Notations: Big Oh, Omega & Theta | Part-1]
             https://www.youtube.com/watch?v=A03oI0znAoc [Asymptotic Notations: Big Oh, Omega & Theta | Part-2]
             https://www.youtube.com/watch?v=lj3E24nnPjI [Best, Worst and Average Case Analysis]
             https://www.youtube.com/watch?v=9TlHvipP5yA [Time Complexity - "For" loops different examples | Part-1]
             https://www.youtube.com/watch?v=9SgLBjXqwd4 [Time Complexity - "For" loops different examples | Part-2]
             https://www.youtube.com/watch?v=p1EnSvS3urU [Time Complexity - "While" & "if"]
             https://www.youtube.com/watch?v=NI4OKSvGAgM [Properties of Asymptotic Notations]

Lalitha Natraj - https://www.youtube.com/watch?v=Yffvd3pkTW4 [Time Complexity - Bubble Sort]

 */
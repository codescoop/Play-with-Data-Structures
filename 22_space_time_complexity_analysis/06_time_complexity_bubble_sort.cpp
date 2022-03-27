/*
    Time Complexity Bubble Sort

    How to do analysis?
    - Practical Approach  : Run each and every algoirithm & then decide which one is better. 
                            NOTE: it may be infeasible to code all the algorithm & then check the complexity
                            as it will waste a lot of time.
    - Theoretical Approach : Judge the complexity of algorithm before we write the code. [Mostly Preferred]

      Eg: We will try to analyse bubble sort for a given input N. 
          i.e calculate how much time does it take to execute the code for value N.
          
          - So, we will count the number of insturctions because time is directly proportional to number of 
            instruction processor execute & no of instruction is directly proportional to input N.
            i.e    time ->  instructions -> f(N)
          Thus, for each value of N, we will try to find out how much instuctions will it run as per the
          rule & condition mentioned in the code.

    -------------------------------------------------------------------
    // bubble sort
    void bubble_sort(int arr[], int n)
    {   
        // Outer Loop
        for (int i = 1; i < n; i++)
        {   
            // Inner Loop
            for (int j=0; j < (n-i); j++) 
            {                                          
                // pairwise swapping                   
                if (arr[j] > arr[j + 1])           
                {                                      
                    swap(arr[j], arr[j + 1]);      
                }                                      
            }                                          
        }
    }

    Assume, array size = n
     _when__i___ | ____j_(running)__
            1    |    n-1 (times)
            2    |    n-2 (times)
            3    |    n-3 (times)
           ...   |    ...
           ...   |    ...
           n-2   |     3  (times)
           n-1   |     2  (times)
            n    |     1  (times)

    So, adding j values,
    = 1+2+3+4+....+n
    = (arithmetic progression:sum of first n natural numbers)
    =  _n_*_(n+1)_
           2
    =  _n^2_+_n_
           2
    =  O(n^2)

    Time Complexity = O(n^2)


    Worst Case
    - In the worst-case scenario, the outer loop runs O(n) times.
    - As a result, the worst-case time complexity of bubble sort is O(n*n) = O(n^2).

    Best Case
    - In the best-case scenario, the array is already sorted, but just in case, bubble sort 
      performs O(n) comparisons.
    - As a result, the time complexity of bubble sort in the best-case scenario is O(n).

    Average Case
    - Bubble sort may require (n/2) passes and O(n) comparisons for each pass in the average case.
    - As a result, the average case time complexity of bubble sort is 
        O(n/2 x n) = O(n/2 x n) = O(n/2 x n) = O(n/2 x n) = O(n^2).

    Reference :- 
    Lalitha Natraj - https://www.youtube.com/watch?v=Yffvd3pkTW4
                 
*/
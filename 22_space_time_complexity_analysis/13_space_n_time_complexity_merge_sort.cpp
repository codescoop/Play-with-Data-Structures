/* 

    TOPIC - Space & Time Complexity - Merge Sort

    -----------------------------------------------------------------------------------------------------
    // Time Complexity
    
                                           ___________
    merge_sort(arr,s,e)                   |_|_|_|_|_|_|       size = n
    {                                     ___/_    _\___
        while(s<e){                      |_|_|_|  |_|_|_|     // divide into n/2
            m = (s+e)/2;                    .        .           ...
            merge_sort(arr,s,m);            .        .        // merge
            merge_sort(arr,m+1,e);         __\______/_
            merge(arr,m,s,e)              |_|_|_|_|_|_|       // merge
        }                                
    }                                    

    If T(n) is the total time to sort the complete array.

    Then this time include 3 parts:
              divide   divide   merge
    T(n)   =  T(n/2) + T(n/2) + T(merge array of size n/2 = n iterations)
    
    So,
    T(n)   = 2T(n/2) + T(merge array of size n/2 = n iterations)
    T(n/2) = 2T(n/4) + T(merge array of size n/4 = n/2 iterations)
    T(n/4) = 2T(n/8) + T(merge array of size n/8 = n/4 iterations)
    ...
    ...
    ...
    Now, the recurrence is, T(n) = 2T(n/2) + k*n
                                   divide   merge

    Lets solve the recurrence:-
    T(n)    =  2T(n/2) +  k*n
    2T(n/2) =  4T(n/4) + 2k*n/2    (after multiplying and dividing both side by 2)
    4T(n/4) =  8T(n/8) + 4k*n/4    (after multiplying and dividing both side by 2)
    ...
    ...
     T(1)   =     0    +  k*n      (Note: when n=1, time taken to divide is 0)
    ----------------------------- // By adding all the above equations on both sides & cancellation, we can get the total time
             logn
     T(n)  =  ∑ k*n
             i=1
            (NOTE: From coming from array size n to 1, we have taken logn steps) 
           = kn*logn
           = nlogn
           = O(nlogn)
           
    Time Complexity = O(nlogn)


    -----------------------------------------------------------------------------------------------------
    // Space Complexity

    Now, The space in merge sort algorithm is used by two types of functions:
                             
                             Space Complexity
                             /            \
                Recursive Call stack      Auxiliary Array in merge function
                           |                     O(n)
                           |
        (At any give time, we can have atmost logN  function calls in call stack)
                    O(logn)
    
    So, Space Complexity = O(logn + n)
                         = O(n)

    -----------------------------------------------------------------------------------------------------
    Thus,
    Time Complexity  = O(nlogn)
    Space Complexity = O(n)


    -----------------------------------------------------------------------------------------------------

    Reference - https://www.youtube.com/watch?v=279cymdrmdg [GATE Applied Course]
 */
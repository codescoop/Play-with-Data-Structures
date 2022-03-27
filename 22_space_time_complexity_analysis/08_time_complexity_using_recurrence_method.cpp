/*
    TOPIC - Time Complexity Using Recurrence Method
    
    - Bubble Sort 
    - Binary Search

    -------------------------------------------------------------------
    // bubble sort
             _________________
    Array:  |_|_|_|_|_|_|_|_|_|
            -------T(n)--------
             _________________
            |_|_|_|_|_|_|_|_|X|
            ------T(n-1)----
    
    If T(n) is the total time to sort the complete array.
    
    Then this time include 2 parts:
    T(n) = k*n + T(n-1)
    - k*n    = Time to move one element to the last (i.e k*n where k=some constant work, n=total array elements)
    - T(n-1) = Time taken to sort the smaller array

    So, the recurrence is, T(n) = k*n + T(n-1)

    Lets solve the recurrence:-
     T(n)  =   k*n   + T(n-1)
    T(n-1) = k*(n-1) + T(n-2)
    T(n-2) = k*(n-2) + T(n-3)
     ...   =  ...    +  ...
     ...   =  ...    +  ...
     T(3)  =  k*(3)  +  T(2)
     T(2)  =  k*(2)  +  T(1)
     T(1)  =  k*(1)  +   0
    ---------------------------- // By adding all the above equations, we can get the total time
     T(n)  = k*n + k*(n-1) + k*(n-2) + ...... + k*(1)
           = k*(n + n-1 + n-2 + ..... 3 + 2 + 1)
           = _k*_n*(n-1)_
                 2
           = O(n^2)
           
    Time Complexity = O(n^2)


    -------------------------------------------------------------------
    // binary search
             _________________
    Array:  |_|_|_|_|_|_|_|_|_|   size = n
            -------T(n)--------
             _________________
            |_|_|_|_|_|X|X|X|X|   size = n/2
            --T(n/2)---
    
    If T(n) is the total time to search the complete array.

    Then this time include 2 parts:
    T(n) = k + T(n/2)
    - k      = To convert a array from size n to size n/2 takes only constant time k because we just have find the mid.
    - T(n/2) = Time taken to do binary search on the smaller array

    So, the recurrence is, T(n) = k*n + T(n-1)

    Lets solve the recurrence:-
     T(n)  =   k  + T(n/2)
    T(n/2) =   k  + T(n/4)
    T(n/4) =   k  + T(n/8)
     ...   =   ...    +  ...
     ...   =   ...    +  ...
     T(1)  =   k  +   0
    ---------------------------- // By adding all the above equations, we can get the total time
             logn
     T(n)  =  ∑ k
             i=1
            (NOTE: From coming from array size n to 1, we have taken logn steps) 
           = k*logn
           = logn
           = O(logn)
           
    Time Complexity = O(logn)
                 
*/
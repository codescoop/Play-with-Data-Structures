/* 

    TOPIC - Space & Time Complexity - Quick Sort

    -----------------------------------------------------------------------------------------------------
    // Time Complexity
         ___________
        |_|_|_|_|_|X|       size = n
              |    p (pivot)           
         _____|_____
        |_|_|X|_|_|_|
             p
       

    If T(n) is the total time to sort the complete array.

    Then this time include 3 parts:
            divide     divide     partition function
    T(n) =  T(n-p)  +  T(p-1)  +  k*n
    
    Now, assume p (i.e pivot) is always at MID,
    So, p = n/2
    T(n)  =   T(n -_n_)  + T(_n_- 1) + k*n
                    2          2
    T(n)  =   T(n/2)     + T(n/2)     + k*n
    T(n)  =   2T(n/2) + k*n

    Now, the recurrence is, T(n) = 2*T(n/2) + k*n
                                   divide     partition function

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
           
    Time Complexity = O(nlogn) (For Average Case)

    -----------------------------------------------------------------------------------------------------
                   _________
    Worst Case => |1|2|3|4|5|
                           p
                         
            divide     divide     partition function
    T(n) =  T(n-p)  +  T(p-1)  +  k*n
    
    putting p = n-1
    T(n) =  T(n-n-1)  +  T(n-1-1)  +  k*n
         =  T(1)      +  T(n-2)    + k*n
         =  T(n-1) + k*n

    Now, the recurrence is, T(n) =  T(n-1) + k*n

    Lets solve the recurrence:-
    T(n)   = T(n-1) + k*n
    T(n-1) = T(n-2) + k*(n-1)
    ...
    ...
    T(1)   =    0   + k
    ------------------------- (after adding & cancellation)
    T(n)   =  k + 2k + 3k +...+ (n-1)k + nk)
           =  k*(1+2+3+...n)
           =  O(n^2)

    Time Complexity = O(nlogn) (For Worst Case)
    (NOTE: To overcome this worst case using "Randomized Quick Sort"
           In which we shuffle the entire array before  sorting)

    -----------------------------------------------------------------------------------------------------
    // Space Complexity

    We know quick sort is a Inplace Sorting Algorithm (i.e it doesn't use extra array like merge sort)
                             
    Space Complexity =  Recursive Call stack
                     =  (At any give time, we can have atmost logN  function calls in call stack)
                     =  O(logn)
    
    So, Space Complexity = O(logn)

    -----------------------------------------------------------------------------------------------------
    Thus,
    Time Complexity  = O(nlogn) (For average case)
                     = O(n^2)   (For Worst Case)       (Solution: Use Randomized Quick Sort)
    Space Complexity = O(logn)


    -----------------------------------------------------------------------------------------------------
 */
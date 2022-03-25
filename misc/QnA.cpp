/* 
    Question & Answers

    INDEX:
    Q1: Basic Maths Concepts
    Q2: Why start + (end – start)/2 is preferable method for calculating middle of an array
        over (start + end)/2 ?
    Q3: Why did we make an array ofsize 100005?
    Q4: Can an array size be more than 100000 in C++? If so, how?
    Q5: I need to store about 10^7 elements in an array. Such a large size is not permissible. 
        I thought about using pointers but that is giving an error. How should we go about storing 
        the elements when the number of elements is too large as of the order of 10^7?
    Q6: Calculate-power-function
    Q7: Sequence [1 + 1/2 + 1/3 + 1/4 + .. + 1/n] = logn. How ?
    Q8: Program to find sum of series [1 + 1/2 + 1/3 + 1/4 + .. + 1/n]

------------------------------------------------------------------------------------------
Q1: Basic Maths Concepts

S1: Permutation & Combination - https://www.mathsisfun.com/combinatorics/combinations-permutations.html
    Pascal's Triangle         - https://www.mathsisfun.com/pascals-triangle.html
    Logarithms & Exponents    - https://www.mathsisfun.com/algebra/logarithms.html


------------------------------------------------------------------------------------------
Q2: Why start + (end – start)/2 is preferable method for calculating middle of an array
    over (start + end)/2 ?

S2: Because (start + end)/2 can caused OVERFLOW !
    when "start" and "end" are all about INT_MAX , then (start+end) of course will be overflow !
    (Note that end - start may overflow, but only if start < 0 or end < 0.)
    
    Ref- https://stackoverflow.com/questions/38688028/why-prefer-start-end-start-2-over-start-end-2-when-calculating-the


------------------------------------------------------------------------------------------
Q3: Why did we make an array ofsize 100005?
    
S3: As given in the question that N goes upto 10^5, so we take an array of size of 10^5 + 5 so that 
    maximum number of elements can accumulate in that array and we usually take few elements more than
    the maximum number of the elements to access elements like n, or n+1 if need be.

    There is no fixed rule to take the size of array as 100005…we generally take the size of the array 
    as the constraints plus 5. we add the extra 5 so that if at any point i exceeds the the maximum value
    of the constraints in the last iteration of loop, and tries to access a[100001] (for ex.), 
    the program doesn’t give runtime error.



------------------------------------------------------------------------------------------
Q4: Can an array size be more than 100000 in C++? If so, how?

S4: When you declare a local variable as an array, it is restricted to the size of the stack.
    To have larger arrays, you need to either declare it as a static variable or in file scope

    // This array is in file scope 
    int arr[10000000]; 
    
    int fn(int param) 
    { 
        // Causes stack overflow 
        int arr1[10000000]; 
        
        // This works fine, same storage everytime this function is called 
        static int arr2[10000000] 
    } 

    Static variables live in what is called the static heap. Ideally you should use new or malloc to 
    allocate memory on the runtime heap, unless you know beforehand how much you need.
    I have a suspicion you may be asking this because you tried using a large array in Turbo C++
    In that case you should know that since Turbo C++ is a legacy compiler built for 16 bit processors,
    the maximum contiguous array you can have is 64 KB, without using complex tricks involving 
    8086 segmented memory addressing.




------------------------------------------------------------------------------------------
Q5: I need to store about 10^7 elements in an array. Such a large size is not permissible. 
    I thought about using pointers but that is giving an error. How should we go about storing 
    the elements when the number of elements is too large as of the order of 10^7?

S5: In a C/C++ function, the local memory (whatever memory you allocate statically inside the function)
    is stored in a stack. The stack memory has limitations. Generally that limit is around 4MB. 
    This limit is configurable. So, if you calculate, that turns out to be 10^6 ints roughly, which means
    usually you can't statically allocate memory beyond 10^6 ints in a function and if you do, you get a
    runtime error.

    If you globally allocate some space (statically or dynamically), you can use memory even beyond 
    10^6 ints. Here, the limitation is enforced by the address space available in the system or it may
    be configured in the execution environment. 
    For example, SPOJ Pyramid cluster enforces 256MB memory limit and SPOJ Cube cluster has a limit 
    of 1536MB. If you use memory beyond that, you will receive a SIGKILL on SPOJ/Codechef.

    So for your use case, you can globally define an array of 10^7 ints (~40MB), chars (~10MB) or 
    long longs (80MB).

------------------------------------------------------------------------------------------
Q6: Calculate-power-function

S6: 1. Naive Iterative approach
    2. Divide and Conquer approach
    3. Optimized divide and conquer approach
    Reference: AfterAcademy  - https://afteracademy.com/blog/calculate-power-function
               TechieDelight - https://www.techiedelight.com/power-function-implementation-recursive-iterative/
               StackOverflow - https://stackoverflow.com/questions/2882706/how-can-i-write-a-power-function-myself


------------------------------------------------------------------------------------------
Q7: Sequence [1 + 1/2 + 1/3 + 1/4 + .. + 1/n] = logn. 
    How ?

S7: logn
                                                                      n        n
    There is no simple closed form. But a rough estimate is given by: ∑ 1/r ≈ ∫ dx/x = logn
                                                                     r=1     1
    Reference: https://math.stackexchange.com/questions/3367037/sum-of-1-1-2-1-3-1-n
 

------------------------------------------------------------------------------------------
Q8: Program to find sum of series 1 + 1/2 + 1/3 + 1/4 + .. + 1/n

S8: If inverse of a sequence follows rule of an A.P i.e, Arithmetic progression, then it is said to be 
    in Harmonic Progression.
    In general, the terms in a harmonic progression can be denoted as: 1/a, 1/(a+d), 1/(a+2d), 1/(a+3d) … 1/(a+nd). 
    As Nth term of AP is given as ( a + (n – 1)d). 
    Hence, Nth term of harmonic progression is reciprocal of Nth term of AP, which is : 1/(a + (n – 1)d) 
    where “a” is the 1st term of AP and “d” is the common difference.
    Reference: GeeksForGeeks - https://www.geeksforgeeks.org/c-program-find-sum-series-1-12-13-14-1n/


------------------------------------------------------------------------------------------
Q9: 

A9:

------------------------------------------------------------------------------------------


 */
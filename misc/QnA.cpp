/* 
    Question & Answers

Q:  Basic Maths Concepts

S:  Permutation & Combination - https://www.mathsisfun.com/combinatorics/combinations-permutations.html
    Pascal's Triangle         - https://www.mathsisfun.com/pascals-triangle.html
    Logarithms & Exponents    - https://www.mathsisfun.com/algebra/logarithms.html

Q:  Why start + (end – start)/2 is preferable method for calculating middle of an array
    over (start + end)/2 ?

S:  Because (start + end)/2 can caused OVERFLOW !
    when "start" and "end" are all about INT_MAX , then (start+end) of course will be overflow !
    (Note that end - start may overflow, but only if start < 0 or end < 0.)
    
    Ref- https://stackoverflow.com/questions/38688028/why-prefer-start-end-start-2-over-start-end-2-when-calculating-the


Q:  Why did we make an array ofsize 100005?
    
S:  As given in the question that N goes upto 10^5, so we take an array of size of 10^5 + 5 so that 
    maximum number of elements can accumulate in that array and we usually take few elements more than
    the maximum number of the elements to access elements like n, or n+1 if need be.

    There is no fixed rule to take the size of array as 100005…we generally take the size of the array 
    as the constraints plus 5. we add the extra 5 so that if at any point i exceeds the the maximum value
    of the constraints in the last iteration of loop, and tries to access a[100001] (for ex.), 
    the program doesn’t give runtime error.



Q:  Can an array size be more than 100000 in C++? If so, how?

S:  When you declare a local variable as an array, it is restricted to the size of the stack.
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




Q:  I need to store about 10^7 elements in an array. Such a large size is not permissible. 
    I thought about using pointers but that is giving an error. How should we go about storing 
    the elements when the number of elements is too large as of the order of 10^7?

S:  In a C/C++ function, the local memory (whatever memory you allocate statically inside the function)
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

Q:  calculate-power-function

S:  1. Naive Iterative approach
    2. Divide and Conquer approach
    3. Optimized divide and conquer approach
    Reference: AfterAcademy  - https://afteracademy.com/blog/calculate-power-function
               TechieDelight - https://www.techiedelight.com/power-function-implementation-recursive-iterative/
               StackOverflow - https://stackoverflow.com/questions/2882706/how-can-i-write-a-power-function-myself

Q:  

 */
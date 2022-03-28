/*
    TOPIC - Space Complexity - Introduction

    Space Complexity - Space complexity of an algorithm quantifies the amount of space or memory
                       taken by an algorithm to run as a function of the length of the input.

    In Space complexity we measeure how much maximum memory the algorithm is going to consume (apart from
    the Input Space i.e we only count the extra space that we use) in the worst case when algo is executing,
    in terms of Input Size. 

    - Space Complexity of an algorithm is the total space taken by the algorithm with respect to the input size. 
    - Auxiliary Space is the extra space or temporary space used by an algorithm. 
    - Space complexity includes both Auxiliary space and space used by input.

    -------------------------------------------------------------------------------------
    Eg: Bubble Sort
        Space Complexity = O(1)
        As, bubble sort is an Inplace Sorting algorithm. That means we are given the input array & we don't
        need any extra memory to store any data, except we need a temporary variable.
        
    NOTE: If we create a fixed number of variables to run an algorithm, that is fine & 
            we can say, the space complexity is O(1) because it is taking constant number of variables to
            solve an algorithm


    -------------------------------------------------------------------------------------
    Eg: Fibonacci
        
        There are different ways:
                                                   | Space Complexity | Time Complexity |
        - Fibonacci using 3 variables              |      O(1)        |      O(n)       |
        - Fibonacci using Array                    |      O(n)        |      O(n)       |
        - Fibonacci using recursion                |      O(n)        |      O(2^n)     |
        - Fibonacci using Matrix Exponentiation    |      O(logn)     |      O(logn)    |


        // Fibonacci using 3 variables
           - int a,b,c  | c=a+b
           Now, as we taking constant number of variables to solve the algorithm.
           So, Auxiliary Space = O(1)


        // Fibonacci using Array
                    ____________________
            a[] =  |0|1|2|3|5|....|_|_|n|

           - int a[n] = a[i-1] + a[i-2]
           Now, we are using an array of size n.
           So, Auxiliary Space = O(n)


        // Fibonacci using Recursion
           int f(int n)
           {                             Call Stack                          Recursion Tree
               // base case
               if(n==0 or n==1)                                                  4        
               {                          |________|                           /    \     
                   return n;              |________|                          3      2    
               }                          |__n=1___|                         / \    / \   
               // recursive case          |__n=2___| f1=1  f2=0             2   1  1   0  
               int f1 = f(n-1);           |__n=3___| f1=1  f2=1            / \            
               int f2 = f(n-2);           |__n=4___| f1=2  f2=1           1   0           
               return f1 + f2;            |__main__| f=3                                 
           

           So, graph of the auxiliary space:
                   ^
                   |
                   |___________O(n)______
          (space)  |    /\/\
                   |   /    \/\/\
                   |  /          \....
                   '--------------------->
                           (time)

           So, Auxiliary Space = O(n)
    }
*/
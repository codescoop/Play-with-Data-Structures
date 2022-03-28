/*
    TOPIC - Time Complexity of Recursion

   -------------------------------------------------------------------
    Eg: fib(n) = fib(n-1) + fib(n-2)

    - Count the total time we are spending at every node 
      (i.e we are just summing up answers. So, it is taking constant time.)
    - Now, count the total number of nodes in the recursion tree. 
      (i.e that will give us the idea of complexity.)

                                          f(n)                                1 node  (i.e 2^0)
                                      /            \
                             f(n-1)                   f(n-2)                  2 node  (i.e 2^1)
                           /      \                 /       \
                     f(n-2)       f(n-3)        f(n-3)       f(n-4)           4 node  (i.e 2^2)
                    /     \       /    \       /     \       /    \           
                   o       o      o     o     o      o      o     o           8 node  (i.e 2^3)
                  /  \   /  \   /  \  /  \   /  \   /  \   /  \  /  \        
                  o  o   o  o   o  o  o  o   o  o   o  o   o  o  o  o        16 node  (i.e 2^4)
                  ...              ...            ...              ...
                  ...              ...            ...              ...
                  ...              ...            ...              ...
                  /  \  /  \  /  \/  \  /  \  /  \  /  \  /  \/  \.........   
    (base case)  1   0  ......   .....   .....     .....    ......   ......   n node  (i.e 2^(n-1))


    Now, k =  total time spend at each node (i.e total instruction executed at each node)
    
    So,  =>   k*(1 + 2 + 4 + 8 + 16 + ..... 2^n-1)
         =    k*( formula to find the sum of the first n terms of the geometric sequence)
         =    k * _(2^(n-1)_-_1)_
                         n-1
         =    O(2^n)

    Time Complexity = O(2^n)  i.e  Exponential

   -------------------------------------------------------------------
    Now, for unit increase in Input, the time to execute that algorithm will double.
    eg: when n=5  time=10s 
             n=6  time=20s 
             n=7  time=30s 
             ...
             ...

    NOTE: In O(2^n) time complexity (i.e Exponential)
          if n is small, 
          i.e n<=20, then 2^20 (instructions are executed)
                        = 2^10 * 2^10
                        = 1000 * 1000                     // 2^10 = 1024 ~ 1000
                        = 10^6 (instructions are executed)
          
          So, if we have n=30 or n=40 in any problem, this algorithm will not work.
    
    Now, The general rule of thumb, 
         In 1-sec time limit, we can do 10^8 operations. 
            (i.e  1 sec -> 10^8 operations)
         So, if n=40 then 2^40 operations ~= 10^12 operations (i.e it will take 10^4 seconds)
                                              So, it will give time limit exceeded error.
                n=30 then 2^30 operations ~= 10^9 operations (i.e it will take 10^4 seconds)
                                              So, it will give time limit exceeded error.
                              
    So, we should avoid using this complexity.
   -------------------------------------------------------------------
*/
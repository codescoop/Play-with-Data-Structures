/*
    TOPIC - Time Complexity Exercise

    -------------------------------------------------------------------------------------
    // Exercise-I

    for(i=0; i<=n-1; i++)   
    {                            
        for(j=i+1; j<=k; j++)
        {
            constant number of operations.
        }   
    }                      

      j=0          j=k
      |-------------|---------------|
      1             k              n-1

    = k+(k-1)+....+1+0+0+0+..........
    =    (k^2       +  (n-1-k)
    =    O(n + k^2)
    =    O(n^2) if k~N 

    Time Complexity = O(n^2) 


    -------------------------------------------------------------------------------------
    // Exercise-II

    for(i=0; i<=n-1; i++)   
    {                            
        for(j=i+1; j<=n; j++)
        {
            constant number of operations.
        }   
    }                            

    ___i__|___j___
       1  |   n
       2  |  n-1
       3  |  n-2
      ... |   .
      ... |   .
      ... |   .
      n-2 |   3
      n-1 |   2
       n  |   1

    Now, when the loop ends then,            
       = (1+2+3+5+...+n)                
       = __n_*_(n+1)__                  
             2                          
       = __(n^2)_+_1__                  
                2                            
       =   (n^2)

    Time Complexity = O(n) 


    -------------------------------------------------------------------------------------
    // Exercise-III

    for(i=0; i<=n-1; )
    {                            
        for(j=0; j<k; j++)
        {
            constant number of operations.
        }   

        i = i+j;
    }
    Now, the inner loop will is running for k-times.
    So, value of j when inner will terminate will be k (i.e j=k)
    therefore, the outer loop will increment by (i+k) each time. 
    
    Thus, Outer loop iterate for n/k times 
        & Inner loop iterate for  k times.
    
    So, time complexity = outer loop * inner loop
                        = _n_ * k
                           k
                        =  n

    Time Complexity = O(n) 
*/
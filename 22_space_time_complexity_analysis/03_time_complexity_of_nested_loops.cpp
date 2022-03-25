/*
    Topic - Time Complexity: NESTED LOOP Examples

    Find the time complexity of below functions:-

    --------------------------------------------------------------------------

    void test1()                                                     
    {                                                                
        int a[n][n] = {{1,2,3,4, ..... upto n},                      
                       {1,2,3,4, ..... upto n},                      
                       {1,2,3,4, ..... upto n},                      
                       {         .....       }                       
                       {         .....       }                       
                       {        upto n       }};                     
                                                                     
        for(int i=1; i<n; i=i+1)                                     
        {                                                            
            for(int j=1; j<n; j=j+1)                                 
            {                                                        
                cout << a[i][j] << ",";                              
            }                                                        
        }                                                            
    }                                                                
    Time Complexity:                                                 
    __when_i__ |  ___j_(runs)____ | ___Output____                    
        1      |     n (times)    |   1,2,3,4...n                    
        2      |     n (times)    |   1,2,3,4...n                    
        3      |     n (times)    |   1,2,3,4...n                    
        4      |     n (times)    |   1,2,3,4...n                    
       ...     |        ...       |   ...                            
       ...     |        ...       |   ...                            
        n      |     n (times)    |   1,2,3,4...n                    
                                                                     
    So, adding all j,                                                
      = n+n+n+n+n+ .... +n                                           
      = n^2                                                          
                                                                     
    Time Complexity = O(n^2)                                         

    --------------------------------------------------------------------------

    void test2()                                                     
    {                                                                
        for(int i=1; i<=n; i=i+1)                                    
        {                                                            
            for(int j=1; j<=i; j=j+1)                                
            {                                                        
                cout << "*";                                         
            }                                                        
        }                                                            
    }                                                                
    Time Complexity:                                                 
    __when_i__ |  ___j_(runs)____ | __Output___                      
        1      |     1 (times)    |   *                              
        2      |     2 (times)    |   **                             
        3      |     3 (times)    |   ***                            
        4      |     4 (times)    |   ****                           
       ...     |        ...       |   ...                            
       ...     |        ...       |   ...                            
        n      |     n (times)    |   ...                            
                                                                     
    So, adding all j,                                                
      = 1+2+3+4+ ..... +n                                            
      = ___n*(n+1)___                                                
             2                                                       
      = ___(n^2)+n___                                                
              2                                                      
                                                                     
    Time Complexity = O(n^2)                                         

    --------------------------------------------------------------------------

    void test3()                                                     
    {                                                                
        for(int i=1; i<=n; i=i+1)                                    
        {                                                            
            for(int j=1; j<=pow(i,2); j=j+1)                         
            {                                                        
                for(int k=1; k<=n/2; k=k+1)                          
                {                                                    
                cout << "*";                                         
                }                                                    
            }                                                        
        }                                                            
    }                                                                
    Time Complexity:                                                 
    __when_i__ |  __j_(runs)__________ | __k___                      
        1      |   1 (times) i.e 2^1   *   n/2                       
        2      |   4 (times) i.e 2^2   *   n/2                       
        3      |   9 (times) i.e 3^2   *   n/2                       
        4      |  16 (times) i.e 4^2   *   n/2                       
       ...     |      ...              *   ...                       
       ...     |      ...              *   ...                       
        n      * n^2 (times) i.e n^2   *   n/2                       
                                                                     
    So, adding all (j*k),                                            
      = 1*(n/2) + 4*(n/2) + 9*(n/2) + 16*(n/2) +  ..... + n^2 *(n/2) 
      = (n/2) * (1+4+9+16+ ..... + n^2)                              
      = (n/2) * (sum of square of first n natural numbers)           
      =  _n_  * ___n*(n+1)*(2n+1)___                                 
          2             2                                            
                                                                     
    Time Complexity = O(n^4)                                         

    --------------------------------------------------------------------------

    void test4()                                                     
    {                                                                
        for(int i=1; i<=n; i=i+1)                                    
        {                                                            
            for(int j=1; j<=n; j=j+i)                                
            {                                                        
                cout << "*";                                         
            }                                                        
        }                                                            
    }                                                                
    Time Complexity:                                                 
    __when_i__ |  ___j_(runs)____                                    
        1      |   n/1 (times)                                       
        2      |   n/2 (times)                                       
        3      |   n/3 (times)                                       
        4      |   n/4 (times)                                       
       ...     |        ...                                          
       ...     |        ...                                          
        n      |   n/n (i.e 1 time)                                  
                                                                     
    So, adding all j,                                                
      = _n_+_n_+_n_+_n_+          +_n_                               
         1   2   3   4              n                                
                                                                     
      = _n_+_n_+_n_+_n_+          + 1                                
         1   2   3   4                                               
                                                                     
      = n * (_1_+_1_+_1_+_1_+        +_1_)                           
              1   2   3   4            n                             
                                                                     
      = n * (log(n) base2)                                           
      = nlogn                                                        
                                                                     
    Time Complexity = O(nlogn)                                       

    --------------------------------------------------------------------------

    void test5()                                                     
    {                                                                
        for(int i=1; i<=n; i=i+1)                                    
        {                                                            
            for(int j=1; j<=n; j=j*2)                                
            {                                                        
                cout << "*";                                         
            }                                                        
        }                                                            
    }                                                                
    Now, Outer Loop is running for:  n    (times)
         Inner Loop is running for:  logn (times)
    
    So, Time Complexity = (No of times Outer Loop runs) * (No of times Inner Loop runs)
                        = n * (logn base2)
                        = O(nlogn) 

    --------------------------------------------------------------------------

    void test6()                                                     
    {                                                                
        for(int i=1; i<=n; i=i+1)
        {
            for(int j=1; j<=n; j=j+1)                                    
            {                                                            
                for(int k=1; k<=n; k=k*2)                                
                {                                                        
                    cout << "*";                                         
                }                                                        
            }                                                            
        }
    }                                                                
    Now, Outer Loop is running for :  n    (times)
         Middle Loop is running for:  n    (times)
         Inner Loop is running for :  logn (times)
    
    So, Time Complexity = (No of times Outer Loop runs)*(No of times Mid Loop runs)*(No of times Inner Loop runs)
                        = n * n * (logn base2)
                        = O(n^2logn) 

    --------------------------------------------------------------------------

    Reference: https://www.youtube.com/watch?v=vRAMUDcwXy4 [Time Complexity Of Nested Loops - With Examples]

*/
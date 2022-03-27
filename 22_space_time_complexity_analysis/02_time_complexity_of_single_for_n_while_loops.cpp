/*
    Topic - Time Complexity: Single FOR & WHILE LOOP Examples

    Find the time complexity of below functions:-

    -------------------------------------------------------------------------------------

    void test1()                             |          void test2()                     
    {                                        |          {                                
        for(int i=1; i<n; i=i+1)             |              for(int i=n; i>0; i=i-1)     
        {                                    |              {                            
            cout << "*";                     |                  cout << "*";             
        }                                    |              }                            
    }                                        |          }                                
    Time Complexity - O(n)                   |          Time Complexity - O(n)           

    -------------------------------------------------------------------------------------

    void test3()                     
    {                                
        for(int i=n/2; i>0; i=i-1)   
        {                            
            cout << "*";             
        }                            
    }                                
    Time Complexity - O(n/2)  = O(n) 

    -------------------------------------------------------------------------------------

    void test4()                             |          void test5()                     
    {                                        |          {                                
        for(int i=1; i<n; i=i+2)             |              for(int i=1; i<n; i=i+3)     
        {                                    |              {                            
            cout << "*";                     |                  cout << "*";             
        }                                    |              }                            
    }                                        |          }                                
                                             |                                             
    Time Complexity:-                        |    Time Complexity:-                        
    ___n__|___Instructions___                |    ___n__|___Instructions___                
       5  |   3 times                        |       5  |   2 times                        
       6  |   3 times                        |       6  |   2 times                        
       7  |   4 times                        |       7  |   2 times                        
       8  |   4 times                        |       8  |   3 times                        
      ... |     ...                          |      ... |     ...                          
                                             |                                             
    So,  5,6  | 3 times                      |    So,  5,6,7   | 2 times                   
         7,8  | 4 times                      |         8,9,10  | 3 times                   
    Time Complexity = ceil O(n/2)            |    Time Complexity = ceil O(n/3)            
                    = O(n)                   |                    = O(n)                   

    ----------------------------------------------------------------------------------------

    void test6()                             |     void test7()                             
    {                                        |     {                                        
        for(int i=1; i<n; i=i*2)             |         for(int i=1; i<n; i=i*3)             
        {                                    |         {                                    
            cout << "*";                     |             cout << "*";                     
        }                                    |         }                                    
    }                                        |     }                                        
                                             |                                              
    Time Complexity:-                        |     Time Complexity:-                        
    ___n___________|__Instructions_|_Output_ |     ___n___________|__Instructions_|_Output_ 
       2 i.e (2^1) |    1 times    | *       |        3 i.e (3^1) |   1 times     | *       
       4 i.e (2^2) |    2 times    | **      |        9 i.e (3^2) |   2 times     | **      
       8 i.e (2^3) |    3 times    | ***     |       27 i.e (3^3) |   3 times     | ***     
      16 i.e (2^4) |    4 times    | ****    |       81 i.e (3^4) |   4 times     | ****    
        ...        |      ...      | ...     |         ...        |     ...       | ...     
        ...        |      ...      | ...     |         ...        |     ...       | ...     
        2^n        |       n       | ...     |         3^n        |      n        | ...     
                                             |                                              
    Now, take (log base2) both sides         |     Now, take (log base3) both sides         
    log(2^n) base2 |    logn base2           |     log(3^n) base3 |    logn base3           
    n*(log2 base2) |    logn base2           |     n*(log3 base3) |    logn base3           
        n*(1)      |    logn base2           |         n*(1)      |    logn base3           
          n        |    logn base2           |           n        |    logn base3           
                                             |                                              
    Time Complexity = O(logn base2)          |     Time Complexity = O(logn base3)          
                    = o(logn)                |                     = o(logn)                

    ----------------------------------------------------------------------------------------

    void test8()                             |     void test9()                             
    {                                        |     {                                        
        for(int i=n; i>1; i=i/2)             |         for(int i=n; i>1; i=i/3)             
        {                                    |         {                                    
            cout << "*";                     |             cout << "*";                     
        }                                    |         }                                    
    }                                        |     }                                        
                                             |                                              
    Time Complexity:-                        |     Time Complexity:-                        
    ___n___________|__Instructions_|_Output_ |     ___n___________|__Instructions_|_Output_ 
       2 i.e (2^1) |    1 times    | *       |        3 i.e (3^1) |   1 times     | *       
       4 i.e (2^2) |    2 times    | **      |        9 i.e (3^2) |   2 times     | **      
       8 i.e (2^3) |    3 times    | ***     |       27 i.e (3^3) |   3 times     | ***     
      16 i.e (2^4) |    4 times    | ****    |       81 i.e (3^4) |   4 times     | ****    
        ...        |      ...      | ...     |         ...        |     ...       | ...     
        ...        |      ...      | ...     |         ...        |     ...       | ...     
        2^n        |       n       | ...     |         3^n        |      n        | ...     
                                             |                                              
    Now, take (log base2) both sides         |     Now, take (log base3) both sides         
    log(2^n) base2 |    logn base2           |     log(3^n) base3 |    logn base3           
    n*(log2 base2) |    logn base2           |     n*(log3 base3) |    logn base3           
        n*(1)      |    logn base2           |         n*(1)      |    logn base3           
          n        |    logn base2           |           n        |    logn base3           
                                             |                                              
    Time Complexity = O(logn base2)          |     Time Complexity = O(logn base3)          
                    = o(logn)                |                     = o(logn)                

    -------------------------------------------------------------------------------------

    void test10()                            |    void test10()                          
    {                                        |    {                                      
        int i, s, n;                         |        int i, s, n;                       
        i = s = 1;                           |        s = 1;                             
                                             |                                           
        while(i<=n)                          |        for( i=1 ;i<=n; i=i+s)             
        {                                    |        {                                  
            cout << "*";                     |            cout << "*";                   
            s = s+1;                         |            s = s+1;                       
            i = i+s;                         |        }                                  
        }                                    |    }                                      
    }                                        |                                           
                                             
    Time Complexity:                         
   | s | 1 | 2 | 3 | 4 | 5 | .....| k |      
   |---|------------------------------------ 
   | i | 1 | 3 | 6 | 10| 15| .....|upto s>n| 
                                             
    Thus,                                    
    ___i__|___s______________    __i_+_s__   
       1  |   1                              
       3  |   1+2                 (1 + 2) = 3
       6  |   1+2+3               (3 + 3) = 6
      10  |   1+2+3+5             (6 + 4) = 10
     ...  |   ....                  ...      
     ...  |   ....                  ...      
       n  |   1+2+3+5+...+k         ...     
                                             
    Now, when the loop ends then,            
          i > n                              
       = (1+2+3+5+...+k)  > n                
       = __k_*_(k+1)__    > n                
             2                               
       = __(k^2)_+_1__    > n                
                2                            
       =    (k^2)  >   n                     
       =     k    ~=   sqrt(n)               
                                             
    So, time complexity = O(sqrt(n))         

    -------------------------------------------------------------------------------------

    void test11()                         
    {                                     
        for(int i=1; i<=sqrt(n); i=i+1)   
        {                                 
            cout << "*";                  
        }                                 
    }                                     
    Time Complexity - O(sqrt(n))          
    (Example - when finding prime number) 

    ----------------------------------------------------------------------------------------

    void test12()                            |    void test12()                             
    {                                        |    {                                         
        int i, j, n;                         |        int i, j, n;                          
        i = j = 1;                           |         j = 1;                               
                                             |                                              
        while(i < n)                         |        for(i=1; i<n; i=pow(2, pow(2,j)))     
        {                                    |        {                                     
            cout << "*";                     |            cout << "*";                      
            i = pow(2, pow(2,j));            |            j = j+i;                          
            j = j+i;                         |        }                                     
        }                                    |    }                                         
    }                                        |                                              
                                             
   Find time complexity:                     
   Method 1: (using j)                       |    Method 2:  (using n)                      
                                             |                                              
   | j | 1 | 2 |  3 |  4  | ......| k |      |    ___n______________ |  _____i______        
   |---|------------------------------------ |       4 i.e (2^(2^1)) |       1              
   | i | 1 | 4 | 16 | 256 | ......|upto s>n| |      16 i.e (2^(2^2)) |       2              
                                             |     256 i.e (2^(2^3)) |       3              
    Thus,                                    |          ...          |      ...             
     __i_ =  _______j_____                   |          ...          |      ...             
       4  =   (2^(2^1))                      |             (2^(2^n)) |       n              
      16  =   (2^(2^2))                      |                                              
     256  =   (2^(2^3))                      |                                              
     ...  =   ....                           |    Now,   (2^(2^n))   = n                    
     ...  =   ....                           |           Taking (log base2) both sides      
     ...  =   (2^(2^k))                      |        => log(2^(2^n)) = logn                
                                             |        =>    (2^n))    = logn                
    Now, when the loop ends then,            |           Taking (log base2) both sides      
          i > n                              |        => log(2^n) = loglogn                 
       = (2^(2^k))  > n                      |        =>     n    = loglogn                 
       Taking (log base2) both sides         |    So, time complexity = O(loglogn)          
       = log((2^(2^k)))  > logn              |                                              
       =    (2^k)        > logn              |
       Taking (log base2) both sides         |
       =  log(2^k) >  log(logn)              |
       =     k    ~=  log(logn)              |
                                             |
    So, time complexity = O(loglogn)         |
    ----------------------------------------------------------------------------------------

    void test13()                         
    {                                     
        p = 0                              

        for(i=1; i<n; i=i*2)           // loop1
        {                                 
            p++;                  
        }                                 

        for(j=1; j<p; j=j*2)           // loop2
        {                                 
            cout << "*";                  
        }                                 
    }                                     

    As,  time complexity of LOOP-1 = logn

    So,  no of times p is running, 
                            i.e  p = logn

    Now, time complexity of LOOP-2 = log(p)
                                   = log(logn)    // putting p = logn
                                   = loglogn

    Time Complexity - O(loglogn)          

    ----------------------------------------------------------------------------------------
    Summary:-

    ____For_Loop_____________                            Time Complexity
    for(i=1; i<n; i++)                                      O(n)
    for(i=1; i<n; i=i+200)        O(n/200)                  O(n)
    for(i=n; i>1; i--)                                      O(n)
    for(i=1; i<n; i=i*2)          O(logn) base2             O(logn)
    for(i=1; i<n; i=i*3)          O(logn) base3             O(logn)
    for(i=1; i<n; i=i/2)          O(logn) base2             O(logn)
    for(i=1; i*i<n; i++)                                    O(sqrt(n))
    for(i=1,j=1; i<n; i=i+j);j++;                           O(sqrt(n))

    ----------------------------------------------------------------------------------------
    Reference: https://www.youtube.com/watch?v=PZZW5mJydyc [Time Complexity of Single Loops  - With Examples]

*/
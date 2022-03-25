/*
    Topic - Time Complexity: LOOP Examples

    Find the time complexity of below functions:-

    ------------------------------------------------------------------------------
    void test1()                        |      void test2()                       
    {                                   |      {                                  
        for(int i=1; i<=5; i=i+1)       |          for(int i=1; i<=n; i=i+1)      
        {                               |          {                              
            cout << "A";                |              cout << "A";               
        }                               |          }                        
                                        |       
        for(int i=1; i<=n; i=i+1)       |          for(int i=1; i<=n; i=i+1)      
        {                               |          {                              
            cout << "B";                |              cout << "B";               
        }                               |          }                              
    }                                   |      }                                  
    Time Complexity: O(5+n)             |      Time Complexity: O(n+n)            
                   = O(n)               |                     = O(2n)              
                                        |                     = O(n)              

    ----------------------------------------------------------------------------------

    void test3()                             |     void test4()                         
    {                                        |     {                                    
        for(int i=1; i<=n; i=i+1)            |         for(int i=1; i<=5; i=i+1)        
        {                                    |         {                                
            for(int j=1; j<=n; j=j+1)        |             for(int j=1; j<=n; j=j+1)    
            {                                |             {                            
                  cout << "*";               |                   cout << "*";           
            }                                |             }                            
        }                                    |         }                                
    }                                        |     }                                    
    Time Complexity:                         |     Time Complexity:                     
    __when_i__ |  __j_(runs)_____            |     __when_i__ |  __j_(runs)_____        
        1      |   n (times)                 |         1      |   n (times)             
        2      |   n (times)                 |         2      |   n (times)             
        3      |   n (times)                 |         3      |   n (times)             
        4      |   n (times)                 |         4      |   n (times)             
       ...     |      ...                    |         5      |   n (times)             
       ...     |      ...                    |                                          
        n      *   n (times)                 |                                          
                                             |                                          
    So, adding all j,                        |     So, adding all j,                    
      = n+n+n+n+n+......n                    |       = n+n+n+n+n                        
      = n^2                                  |       = 5n                               
                                             |                                          
    Time Complexity = O(n^2)                 |     Time Complexity = O(5*n)             
                                             |                     = O(n)               

    -----------------------------------------------------------------------------------

    void test5()                                                     
    {                                                                
        for(int j=1; j<=3; j=j+1)                                
        {                                                        
            cout << "*";                                         
        }                       

        for(int i=1; i<=5; i=i+1)                                    
        {                                                            
            for(int j=1; j<=n; j=j+i)                                
            {                                                        
                cout << "*";                                         
            }                                                        
        }                                                            
    }                                                                
    Time Complexity = O(3+5n)                                        
                    = O(n)                                           

    --------------------------------------------------------------------------

    void test6()                                                     
    {                                                                
        for(int j=1; j<=5; j=j+i)                                
        {                                                        
            cout << "A";                                         
        }                   

        for(int i=1; i<=4; i=i+1)                                    
        {                                                            
            for(int j=1; j<=n; j=j+i)                                
            {                                                        
                cout << "B";                                         
            }                                                        
        }                

        for(int i=1; i<=2; i=i+1)                                    
        {                                                            
            for(int j=1; j<=n; j=j+i)                                
            {                                                        
                for(int k=1; k<=n; k=k+i)                                
                {                                                        
                    cout << "B";                                         
                }                                                        
            }                                                        
        }                                                            
    }                                                                
    Time Complexity = O(5 + 4n + 2(n^2))                                        
                    = O(2(n^2))                                           
                    = O(n^2)                                           

    --------------------------------------------------------------------------

    void test7()                                                     
    {                                                                
        b = 1

        for(int a=1; a<=n; a=a+1)                                
        {                                                        
            b = a*b;                                             
        }                       

        for(int a=1; a<=b; a=a+1)                                    
        {                                                            
            cout << a;                                               
        }                                                            
    }                                                                

    Findig value of b:
    __when_a__ |  __then_b_____            
        1      |        1                  
        2      |        2                  
        3      |        6                  
        4      |       24                  
        5      |      120                  
       ...     |       ...                 
       ...     |       ...                 
        n      |        n!                 

    Time Complexity = O(n + b)                                        
                    = O(n + n!)
                    = O(n!)                                           

    --------------------------------------------------------------------------

    Reference: https://www.youtube.com/watch?v=VbzMDQgQf28 [Summary Of Time Complexity - Loops - with example]

*/
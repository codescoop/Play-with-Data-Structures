/*
    Topic - Time Complexity: IF & WHILE LOOP Examples

    Find the time complexity of below functions:-

    -------------------------------------------------------------------------------------
    //find GCD/HCF using while loop

    void test1()                             |          void test1()                     
    {                                        |          {                                
        while(m != n)                        |              for( ; m != n; )     
        {                                    |              {                            
            if(m>n)                          |                  if(m>n)             
                m = m-n;                     |                      m = m-n;             
            else                             |                  else          
                n = n-m;                     |                      n = n-m;             
        }                                    |              }                            
    }                                        |          }                                

    ____Assume______|___Instructions___    
       m=6 & n=3    |     2 (time)       Running when, n=3  m=6,3
       m=5 & n=5    |     0 (time)       Not running
       m=16 & n=2   |     8 (time)       Running when, n=2  m=16,14,12,10,8,6,4,2
       m=10 & n=50  |     5 (time)       Running when, m=10 n=50,40,30,20,10


    Time Complexity = O(n/2)
                    = O(n)

          min. time = O(1)  Best Case
          max. time = O(n)  Worst Case

    -------------------------------------------------------------------------------------

    void test2(n)                     
    {                                
        if(n<5)
        {
            cout << 'A';
        }
        else
        {
            for(int i=0; i<n; i++)   
            {                            
                cout << 'B';             
            }                            
        }
    }                            

    For, if case, statement is running 1 (time)  i.e O(1) for if case
       else case, statement is running n (times) i.e O(n) for else case

    Time Complexity = O(n) 
          min. time = O(1)  Best Case
          max. time = O(n)  Worst Case

    -------------------------------------------------------------------------------------
    Reference: https://www.youtube.com/watch?v=p1EnSvS3urU [Time Complexity - "While" & "if"]

*/
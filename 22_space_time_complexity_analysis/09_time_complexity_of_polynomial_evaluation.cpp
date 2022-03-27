/*
    TOPIC - Time Complexity of Polynomial Evaluation
    
    Suppose we have to write a function to evaluatea a polynomial expression.
    p(x) =  a x^n  + b x^(n-1) + c x^(n-2) + ......
    
    Eg: Evaluate  8x^3 + 4x^2 + 3x +2  for x=5
        & find the time complexity of the program.

    So, there are 3 approach to write above program:
    - Using Power Function       [Time Complexity: O(n^2)   ]
    - Using Fast Power function  [Time Complexity: O(nlogn) ]
    - Using Horner’s method      [Time Complexity: O(n)     ]

   -------------------------------------------------------------------
    // Approach-I : Using Power Function
       - A naive way to evaluate a polynomial is to one by one evaluate all terms. 
       - First calculate x^n, multiply the value with cn, 
       - repeat the same steps for other terms and return the sum.
       Time complexity of this approach is O(n^2). As, we are using O(n) approach i.e a simple loop for evaluation of x^n.

    int power(x,n)
    {
        int ans = 1;

        for(i=1; i<=n;i++)
        {
            ans = ans * x; 
        }
    }
    Time Complexity of power function = O(n)

    Now, time taken by power function for below equation:
           p(x) =  a x^n  + b x^(n-1) + c x^(n-2) + ......
    time taken  =     n   +    n-1   +      n-2  + ...... + 1
                = _n*(n+1)_
                      2
                = O(n^2)

    Time Complexity = O(n^2)

   -------------------------------------------------------------------
    // Approach-II : Using Fast Power Function
       - Time complexity is O(nLogn). 
         As, we are using O(Logn) approach for evaluation of x^n.

    int fast_power(int num, int power)
    {
        int ans = 1;
        while(power)
        {
            int last_bit = power&1;
            if(last_bit == 1)
            {
                ans = ans*num;
            }
            num = num*num;        // Square up
            power = power>>1;     // Discard the last bit
        }
        return ans;
    }
    Time Complexity of power function = O(logn)

    Now, time taken by power function for below equation:
           p(x) =  a x^n  + b x^(n-1) + c x^(n-2) + ......
    time taken  =   logn  +   logn    +    logn   + ...... + logn
                =  n * logn
                =  O(nlogn)

    Time Complexity = O(nlogn)
    
    -------------------------------------------------------------------
    // Approach-III : Horner’s method
       - Horner’s method can be used to evaluate polynomial in O(n) time. 
       - To understand the method, let us consider the example of 2x3 – 6x2 + 2x – 1. 
       - The polynomial can be evaluated as ((2x – 6)x + 2)x – 1. 
       - The idea is to initialize result as coefficient of xn which is 2 in this case, 
       - repeatedly multiply result with x and add next coefficient to result. 
       - Finally return result

    // returns value of poly[0]x(n-1) + poly[1]x(n-2) + .. + poly[n-1]
    int horner(int poly[], int n, int x)
    {
        // Initialize result
        int result = poly[0];
    
        // Evaluate value of polynomial using Horner's method
        for (int i=1; i<n; i++)
        {
            result = result*x + poly[i];
        }
        return result;
    }

    // Driver program to test above function.
    int main()
    {
        // Let us evaluate value of 2x3 - 6x2 + 2x - 1 for x = 3
        int poly[] = {2, -6, 2, -1};
        int x = 3;
        int n = sizeof(poly)/sizeof(poly[0]);
        cout << "Value of polynomial is " << horner(poly, n, x);
        return 0;
    }

    Now, time taken by horner function for below equation:
           p(x) =  a x^n  + b x^(n-1) + c x^(n-2) + ......
    time taken  =    1    +   1       +    1      + ...... + 1
                =  n
                =  O(n)

    Time Complexity = O(n)
                 
*/
/*
    Topic: GCD (Euclid's GCD Algorithm)

    - Euclid's Algorithm to computer Greatest Common Divisor
    - Computer HCF & LCM

    Basics:

    - Factors and Multiples : All the numbers that divide a number completely, i.e., without leaving 
                              any remainder, are called factors of that number. 
                 For example, 24 is completely divisible by 1, 2, 3, 4, 6, 8, 12, 24. 
                              Each of these numbers is called a factor of 24 and 
                              24 is called a multiple of each of these numbers.
             
    - LCM (Least Common Multiple): The least number which is exactly divisible by each of the given numbers is called the 
                                   least common multiple of those numbers. 
                      For example, consider the numbers 3, 31 and 62 (2 x 31). 
                                   The LCM of these numbers would be 2 x 3 x 31 = 186.
      
    
    - HCF (Highest Common Factor): The largest number that divides two or more numbers is the 
                                   highest common factor (HCF) for those numbers. 
                      For example, consider the numbers 30 (2x3x5), 36 (2x2x3x3), 42 (2x3x7) & 45 (3x3x5)
                                   3 is the largest number that divides each of these numbers, and 
                                   hence, is the HCF for these numbers

      HCF is also known as Greatest Common Divisor (GCD).

    - GCD (Greatest Common Divisor) of two number is the largest number that divides both the number.
        For example, a = 12           (Factors of 12 = 1,2,3,4,6,12)
                     b = 20           (Factors of 20 = 1,2,4,5,10,20)
                     GCD of (a,b) = 4
      
      NOTE:
    - The Greatest Common Divisor(GCD) is also known as Greatest Common Factor (GCF), 
                                                        Greatest Common Measure (GCM),
                                                        Highest Common Divisor (HCD),
                                                        Highest Common Factor (HCD).
*/


#include <iostream>
using namespace std;

// function to calculate GCD or HCF of two numbers
int gcd(int a, int b)
{
    return b==0 ? a : gcd(b,a%b);
    /* 
        According to Euclid's Algorithm:
         1. GCD(a,b) = GCD(b,a%b)
         2. GCD(a,0) = a
                           ____
         Eg: a = 20     12| 20 |1
             b = 12        _12_ ____
                             8 | 12 |1
                                __8_ ____
                                  4 | 8  |1
                                     _8__ ____
                                      4  | 0  |   <- Stop 
                                                    (GCD = 4)
                                         
    */
}


// function to calculate LCM of two numbers
int lcm (int a, int b, int gcd_val)
{
    int lcm_val = (a*b)/gcd_val;
    return lcm_val;

    /* 
        Optimised Approach
        -  There is a relation between LCM & GCD of two numbers
           i.e  GCD * LCM = a * b 
           so,  LCM = (a*b)/GCD
         
           Eg:  when a = 12
                     b = 20
                   GCD =  4

                   LCM = (12*20)/4
                       = 60

        Naive Approach
        - Eg: when a = 12            2|_12,_20_
                   b = 20            2|  6  10
                                      |  3   5
                 LCM =  2*2*3*5  
                     =  60
            
  
         
    */
}


// function to drive code
int main()
{

    int t;
    cout << "Enter testcases: ";
    cin >> t;

    while(t--)
    {
        int a, b;
        cout << "Enter two number [a & b]: ";
        cin >> a >> b;

        // calculate GCD or HCF
        int gcd_value = gcd(a,b);

        // calculate LCM
        int lcm_value = lcm(a,b,gcd_value);

        cout << "GCD: " << gcd_value << endl;
        cout << "LCM: " << lcm_value << endl;
    }

    return 0;
}

/* 
OUTPUT:
    Enter testcases: 3

    Enter two number [a & b]: 12 20
    GCD: 4
    LCM: 60

    Enter two number [a & b]: 24 15
    GCD: 3
    LCM: 120

    Enter two number [a & b]: 15 24
    GCD: 3
    LCM: 120
 */
/*
    Topic: Modulo Properties

    - We generally use modulo properties to compute large numbers by reducing it into smaller numbers.
    
    Properties of Modulo (%)
    - (a+b)%m = ((a%m)+(b%m))%m

    - (a-b)%m = ((a%m)-(b%m)+m)%m      Eg: a = 8   b = 3    m = 7
                                           (a-b)%m  = (8 - 3) % 7
                                                    = 5 % 7
                                                    = 5
                                           ((a%m)-(b%m)+m)%m  = (8%7 - 3%7 + 7) % 7
                                                              = (1 - 3 + 7) % 7
                                                              = (-2 + 7) % 7
                                                              = 5 % 7
                                                              = 5
    - (a*b)%m = ((a%m)*(b%m))%m

    - (a/b)%m = ((a%m)*(b-inverse % m))%m
         b-inverse is Multiplicative Modulo Inverse
         Eg:  we will be computing modulo inverse of 6 with respect to 7 
              (6*y)%7 ~= 1
              Now, we need a value of y such that modulo of product-of 6 & y by 7 is 1
              So when y =6, then,(6*6)%7
                                 = 36%7
                                 = 1

    CRT (Chinese remainder theorem)
    -  In mathematics, the Chinese remainder theorem states that if one knows the remainders of the 
       Euclidean division of an integer n by several integers, 
       then one can determine uniquely the remainder of the division of n by the product of these integers, 
       under the condition that the divisors are pairwise coprime.

    -  The Chinese remainder theorem is widely used for computing with large integers, as it allows 
       replacing a computation for which one knows a bound on the size of the result by several similar
       computations on small integers.

    -  In its basic form, the Chinese remainder theorem will determine a number p such that, when divided
       by some given divisors, leaves given remainders.



    Problem: We are given two arrays:  num[0...k-1] and rem[0...k-1]. 
             In num[0...k-1], every pair is coprime (gcd for every pair is 1). 
             We need to find minimum positive number x such that:   x % num[0]    =  rem[0], 
                                                                    x % num[1]    =  rem[1], 
                                                                    ------------------------
                                                                    x % num[k-1]  =  rem[k-1]

    Explanation: Basically, we are given k numbers which are pairwise coprime, 
                 and given remainders of these numbers, when an unknown number x is divided by them. 
                 We need to find the minimum possible value of x that produces given remainders. 
    
    Case 1:   Input  :  num[] = {5, 7}, 
                        rem[] = {1, 3}
              Output :  31
              Explanation: 31 is the smallest number such that:
                           (1) When we divide it by 5, we get remainder 1. 
                           (2) When we divide it by 7, we get remainder 3.

    Case 2:   Input:  num[] = {3, 4, 5}, 
                      rem[] = {2, 3, 1}
             Output: 11
             Explanation: 11 is the smallest number such that:
                          (1) When we divide it by 3, we get remainder 2. 
                          (2) When we divide it by 4, we get remainder 3.
                          (3) When we divide it by 5, we get remainder 1.

    Hint: Chinese Remainder Theorem states that there always exists an x that satisfies given congruences.
*/




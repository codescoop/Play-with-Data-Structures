/*
    Topic: LCM
    
    Take the following as input.
    A number (N1)
    A number (N2)
    Write a function which returns the LCM of N1 and N2. Print the value returned.

    Constraints: 0 < N1 < 1000000000 0 < N2 < 1000000000

    Sample Input:  4 
                   6

    Sample Output: 12

    Explanation:  The smallest number that is divisible by both N1 and N2 is called the LCM of N1 and N2.
*/


#include <iostream>
using namespace std;

// function to find GCD (using Euclidean algorithm)
int gcd(int a, int b)
{
    return a==0 ? b : gcd(b%a,a);
}

// function to find LCM
int lcm(int a, int b)
{
    int gcd_value = gcd(a,b);
    int lcd_value = (a * b)/gcd_value;       // As, gcd * lcd = a * b
    return lcd_value;
}

// functon to drive code
int main()
{
    int a, b;
    cout << "Enter Numbers [a & b]: ";
    cin >> a >> b;

    cout << "LCM(a,b) : ";
    cout << lcm(a,b) << endl;

    return 0;
}


/* 
OUTPUT:


APPROACH:

    To find the LCM of two numbers, it is obvious that the LCM will be greater than or equal to 
    the samller number in the two given numbers.

Algorithm:
    - Take input of both the numbers say, N1 and N2.
    - Declare a variable with value with the smallest of the two numbers.
    - put a Infinite loop
    - Inside loop check if the variable can divide both the numbers,
       1. If yes, break.
       2. Otherwise increment the variable and continue.
    - Print the LCM obtained.

Code

    Lang - Cpp

    #include<iostream>
    using namespace std;

    int main() 
    {
        int num1,num2;
        cin >> num1>>num2;

        if(num1>num2)
        {
            int temp = num2;
            num2=num1;
            num1=temp;
        }

        int lcm=num2;
        while(lcm>0)
        {
            if(lcm%num2==0 && lcm%num1==0)
            {
                break;
            }
            lcm++;
        }
        cout << lcm << endl;
        return 0;
    }


    Lang - Java
    The approach is to start with the largest of the 2 numbers and keep incrementing the larger number by
    itself till smaller number perfectly divides the resultant.

    public static int lcm(int n1, int n2)
    {
        int largest = Math.max(n1, n2);
        int smallest = Math.min(n1, n2);

        for(int i = largest;  ;i += largest)
        {
          if(i % smallest == 0)
          {
              return i;
          }
        }
    }
*/
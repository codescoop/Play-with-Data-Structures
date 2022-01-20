/*
    Topic: Bitwise Operators

    The following 6 operators are bitwise operators (work at bit-level) 
    
    - Bitwise operators
      1.  & (Bitwise AND)  - The result of AND is 1 only if both bits are 1
      2.  | (Bitwise OR)   - The result of OR is 1 if any of the two bits is 1
      3.  ^ (Bitwise XOR)  - The result of XOR is 1 if the two bits are different.
      4.  ~ (Bitwise NOT/Complement Operator)  - It takes one number and inverts all bits of it.
    
    - Shift Operators
      5.  << (Bitwise Left Shift)  - It shifts all bits towards the left by a certain number of specified bits
      6.  >> (Bitwise Right Shift) - It shifts all bits towards the right by a certain number of specified bits.

    These operators are necessary because the Arithmetic-Logic Unit (ALU) present in the computer's CPU
    carries out arithmetic operations at the bit-level.

    NOTE: Bitwise operators can only be used alongside char and int data types.
*/

#include <iostream>
using namespace std;

int main()
{
    int a = 12;        // 12 = 00001100 (In Binary)
    int b = 25;        // 25 = 00011001 (In Binary)

    /* 
        Bitwise AND

        In Binary  | In Decimal
        -----------------------
        00001100   |  (12)
      & 00011001   |  (25)
        _________    _________
        00001000   |  (8) 
    */

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a & b = " << (a & b) << endl;


    /* 
        Bitwise OR

        In Binary  | In Decimal
        -----------------------
        00001100   |  (12)
      | 00011001   |  (25)
        _________    _________
        00011101   |  (29) 
    */
    

    cout << "a | b = " << (a | b) << endl;

    /* 
        Bitwise XOR

        In Binary  | In Decimal
        -----------------------
        00001100   |  (12)
      ^ 00011001   |  (25)
        _________    _________
        00010101   |  (21) 
    */
    
    cout << "a ^ b = " << (a ^ b) << "\n\n";


    /* 
        Bitwise NOT or Bitwise Complement Operator

        The bitwise complement operator is a unary operator (works on only one operand).
        It changes binary digits 1 to 0 and 0 to 1.

        It is important to note that the bitwise complement of any integer N is equal to -(N + 1). 
        For example, Consider an integer 35. 
        As per the rule, the bitwise complement of 35 should be -(35 + 1) = -36. 

        In Binary  | In Decimal
        -----------------------
      ~ 00100011   |  (35)
        _________    _________
        11011100   |   ???      =>   (220) or (-36) 
        
        In the above example, we get that the bitwise complement of 00100011 (35) is 11011100. 
        Here, if we convert the result into decimal we get 220.
        However, it is important to note that we cannot directly convert the result into decimal and
        get the desired output. This is because the binary result 11011100 is also equivalent to -36.

        To understand this we first need to calculate the binary output of -36. 
        We use 2's complement to calculate the binary of negative integers.

        2's Complement

        The 2's complement of a number N gives -N.
        In binary arithmetic, 1's complement changes 0 to 1 and 1 to 0.
        And, if we add 1 to the result of the 1's complement, 
        we get the 2's complement of the original number. 

        Eg:   36 = 00100100 (In Binary)
             
              1's Complement =  11011011

              2's Complement :  11011011
                                +      1
                                _________
                                11011100 
        
        Here, we can see the 2's complement of 36 (i.e. -36) is 11011100. 
        This value is equivalent to the bitwise complement of 35 that we have calculated in previous example.
        
        Thus, the bitwise complement of 35 = - (35 + 1) = -36
        i.e. ~35 = -36
    */
    int num1 = 35;
    int num2 = -150;
    
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    
    cout << "~(num1) = " << "~(" << num1 << ") = " << ~num1 << endl;        // Output: -36
    cout << "~(num2) = " << "~(" << num2 << ") = " << (~num2) << "\n\n";    // Output: 149

    /* 
        Left Shift Operator

        The left shift operator shifts all bits towards the left by a certain number of specified bits.
        When we perform a 1 bit left shift operation on it, each individual bit is shifted to the left by 1 bit.
        As a result, the left-most bit is discarded, while the right-most bit remains vacant. 
        This vacancy is replaced by a 0(zero).

        Eg:   (4 << 1) = 8

              In Binary  | In Decimal
              -----------------------
                0100    |   (4)
              _________    _________
                1000    |   (8)            One bit Left Shift


        Right Shift Operator

        The right shift operator shifts all bits towards the right by a certain number of specified bits.
        When we perform a one-bit right shift operation on it, each individual bit is shifted to the right by 1 bit.
        As a result, the right-most bit is discarded, while the left-most bit remains vacant. 
        This vacancy is replaced by a 0(zero).

        Eg:   (4 >> 1) = 2

              In Binary  | In Decimal
              -----------------------
                0100    |   (4)
              _________    _________
                0010    |   (2)            One bit Right Shift



        NOTE: In the above example, the int data type stores numbers in 32-bits 
                                    (i.e. an int value is represented by 32 binary digits)
              However, our explanation for the bitwise shift operators used numbers represented in 4-bits.

              For example, the base-10 number 4 can be represented in 4-bit and 32-bit as:
              4-bit Representation of 4 = 0100
              32-bit Representation of 4 = 00000000 00000000 00000000 00000100
              
              As a result, the bitwise left-shift operation for 4 (and any other number) can be different
              depending on the number of bits they are represented by.
              Because in 32-bit representation, there are many more bits that can be shifted left when 
              compared to 4-bit representation.
    */

    int c = 8;
    int d = 16;
    
    // Shift left Operation
    cout << "Shift left:" << endl;
    cout << "c = " << c << endl;
    cout << "(c << 1) = " << (c << 1) << "\n\n";

    // Shift Right Operation
    cout << "Shift Right:" << endl;
    cout << "c = " << c << endl;
    cout << "(c >> 1) = " << (c >> 1) << "\n\n";


    // Using for loop for shifting number right from 0 bit to 6 bits
    cout << "Right Shift (from 0 bit to 6 bits)" << endl;
    cout << "d = " << d << endl;
    for (int i = 0; i <= 6; i++) 
    {
        cout << "(d >> " << i << ") = " << (d >> i) << endl;
    }

    return 0;
}

/* 
OUTPUT:

    a = 12
    b = 25
    a & b = 8
    a | b = 29
    a ^ b = 21

    num1 = 35
    num2 = -150
    ~(num1) = ~(35) = -36
    ~(num2) = ~(-150) = 149

    Shift left:
    c = 8
    (c << 1) = 16

    Shift Right:
    c = 8
    (c >> 1) = 4

    Right Shift (from 0 bit to 6 bits)
    d = 16
    (d >> 0) = 16
    (d >> 1) = 8
    (d >> 2) = 4
    (d >> 3) = 2
    (d >> 4) = 1
    (d >> 5) = 0
    (d >> 6) = 0

*/
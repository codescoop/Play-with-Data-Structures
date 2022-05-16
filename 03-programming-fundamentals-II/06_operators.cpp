/*
    Operators in C++

    -------------------------------------------------------------
    Summary:
    -------------------------------------------------------------
    
    - Unary Operator  :   ++ --                (Increment & Decrement) 

    - Ternary Operator:   ?:                   (Conditional operator)

    - Binary Operator :   + - * / %            (Arithmetic Operator)
                          & | ^ ~ << >>        (Bitwise Operator)
                          && || !              (Logical Operator)
                          = == += -= *= /= %=  (Assignment Operator)
                          < <= > >= == !=      (Relational Operator / Comparison Operator)


    - Member Access   :  a[b]  *a  &a  a->b  a.b  a->*b  a*b
    - Other           :  a(...)  a,b


    -------------------------------------------------------------
    Detail Reference:
    -------------------------------------------------------------

    - Increment/Decrement  :  ++a
                              --a
                              a++
                              a--

    - Arithmetic Operator  :  a+b       Add
                              a-b       Subtract
                              a*b       Multiply
                              a/b       Divide    (return quotient)
                              a%b       Modulus   (return remainder)

    - Bitwise Operator     :  a&b       Bitwise AND
                              a|b       Bitwise OR
                              a^b       Bitwise XOR
                              ~a        Bitwise NOT  (Binary One's Complement) (bit inversion)
                              a<<b      Left Shift
                              a>>b      Right Shift

    - Logical Operator     :  !a        Logical and       Eg: !(x < 5 && x < 10)
                              a&&b      Logical or        Eg:   x < 5 &&  x < 10
                              a||b      Logical not       Eg:   x < 5 || x < 4

    - Assignment Operator  :  a=b       Assignment operator (=)

                              a==b      Compound assignment
                              a+=b
                              a-=b
                              a*=b
                              a/=b
                              a%=b

                              a&=b      Compound assignment
                              a|=b
                              a^=b
                              a<<=b
                              a>>=b

    - Comparison Operator  :  <         Less than
      (RelationalOperator)    <=
                              >         Greater than
                              >=
                              ==        Equals to
                              !=        Not Equal

                              <=>       Three-Way Comparison operator

    - Member Acceess       :  a[b]      subscript
                              *a        reference
                              &a        dereference (represents memory address of the operand)  Eg: &num; // address of num
                              a->b      member access (used with pointers to access the class or struct variables)
                              a.b       member access (accesses members of struct variables or class objects)
                              a->*b     access pointer
                              a.*b      access pointer

                              ::        Scope resolution operator 
                              ::*       Pointer-to-member declaration (Pointer to class data member "::*")

    - Other                :  a, b      Comma
                              ? :       Conditional ternary operator
                              sizeof    returns the size of data type     Eg: sizeof(int);
                              new       Memory allocation operator
                              delete    Memory release operator
                              endl      Line feed operator
                              setw      Field width operator
                              (type)    C-style type-casting
                              a(...)    "three dots" syntax (...) inside the catch block, 
                                         which will handle any type of exception.
*/

#include <iostream>
using namespace std;

int main(){
    //Comma Operator
    int a,b,c;

    //Assignment Operator
    a=10;
    b=20;
    c=30;

    //Logical Operator
    if(c>a and c>b){
        cout<<"C is largest"<<endl;
    }

    //Ternary Operator
    int x = c%2==0 ? 1 : 0;
    cout<<x<<endl;

    c%2==0 ? cout<<"True" : cout<<"False";
    cout<<endl;

    //Bitwise Operator
    x=5;
    int y=7;
    cout<<"AND "<<(x&y)<<endl;
    cout<<"OR "<<(x|y)<<endl;
    cout<<"XOR "<<(x^y)<<endl;

    //Shift Operator
    x = x<<2;
    cout<<x<<endl;          // Expected answer: 20
    cout<<(y>>1)<<endl;     // Expected answer: 3

    //Unary Operator
    cout<<"Address of x: "<<(&x)<<endl;

    //Post Increment / Decrement Operator
    a=10;
    int d = a++;     //d=10   a=11
    cout<<"Value of d: "<<d<<endl;    
    d = ++a;        // d=12   a=12
    cout<<"Value of d: "<<d<<endl;    

    //Compound Assignment Operator
    a = 10;
    a *= 3;      // a = a*3
    cout<<"A after multiply: "<<a<<endl;
    a %=5;      // a = a%5
    cout<<"A after modulo: "<<a<<endl;

    b=5;
    b <<=1; 
    cout<<"B after left shift: "<<b<<endl;

    return 0;
}
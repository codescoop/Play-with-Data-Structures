/*
    Operators in C++
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
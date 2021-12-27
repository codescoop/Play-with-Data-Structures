/* 
    Topic - Pass by Reference Using Pointers

    Pass by Value :     Passing the copy of variable
    Pass by Reference:  Passing the address of variable
       
*/

#include <iostream>
using namespace  std;

// call by value
void increment_1(int num){        // variable
    num = num +1;
    cout << "[Call by Value] a: "<< num << endl;
}

// call by reference
void increment_2(int *num){        // pointer
    *num = *num +1;
    cout << "[Call by reference] b:"<< *num << endl;
}

int main(){
    int a = 10;
    int b = 10;

    cout << "a : "<< a << endl;
    increment_1(a);                             // Passing the copy of variable
    cout << "[Inside Main] a: "<< a << endl;

    cout << "\nb : "<< b << endl;
    increment_2(&b);                            // Passing the address of variable
    cout << "[Inside Main] b: "<< b << endl;


    return 0;
}

/* 
OUTPUT: 
    a : 10
    [Call by Value] a: 11
    [Inside Main] a: 10

    b : 10
    [Call by reference] b:11
    [Inside Main] b: 11
*/
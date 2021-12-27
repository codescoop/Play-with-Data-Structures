/* 
    Topic - Dereference Operator (*)

    asterisk (*) has many use cases :-
        1. For multiplication           //  5*2
        2. to declaring pointer         //  int * ptr;
        3. to dereference any address   //  *ptr + 1
    
    Dereference:
     - In simple words, dereferencing means accessing the value from a certain memory location against 
       which that pointer is pointing.
     - So, by dereferencing pointer we can access the variable, in which they are pointing to.
       
*/

#include <iostream>
using namespace  std;

int main(){
    int a = 10;
    int *ptr = &a;             // declaration & initilization

    cout << "&a - " << &a << endl;                    // OUTPUT: (Address of bucket "a")
    cout << "ptr - " << &a << "\n\n";                 // OUTPUT: (Address of bucket "a")
    
    // dereferencing
    cout << "*(&a) - " << *(&a) << endl;              // OUTPUT: 10 (value -> address a)
    cout << "*(ptr) - " << *(ptr) << "\n\n";          // OUTPUT: 10 (value -> address stored at ptr) 
    
    cout << "*(&ptr) - " << *(&ptr) << endl;          // OUTPUT: (Address of bucket "a")    [=> value stored at ptr)  =>  value at &ptr] 
    cout << "&(*ptr) - " << &(*ptr) << "\n\n";        // OUTPUT: (Address of bucket "a")    [i.e  *ptr = bucket "a"] 

    // Know the difference :-
    cout << "*(ptr) + 1 - " << *(ptr)+1 << endl;      // OUTPUT:  11  (i.e 10+1)
    cout << "*(ptr+1) - " << *(ptr+1) << "\n\n";      // OUTPUT:  Unknown/Garbage Value  
                                                      //          (value at next memory address)

    // Double Pointer
    int ** newptr = &ptr;
    cout << "Double Pointer: " << endl;
    cout << "newptr: " << newptr << endl;             // OUTPUT: (address of ptr)
    cout << "&ptr: " << &ptr << endl;                 // OUTPUT: (address of ptr)

    return 0;
}

/* 
OUTPUT: 

    &a - 0x7ffe49b6db94
    ptr - 0x7ffe49b6db94

    *(&a) - 10
    *(ptr) - 10

    *(&ptr) - 0x7ffe49b6db94
    &(*ptr) - 0x7ffe49b6db94

    *(ptr) + 1 - 11
    *(ptr+1) - 1236720532

    Double Pointer: 
    newptr: 0x7ffe49b6db98
    &ptr: 0x7ffe49b6db98
*/
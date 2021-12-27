/* 
    Pointers
    - Pointer is a variable that stores the address of another variable
      Syntax:   datatype * variable_name
    - The size of pointer doesn't depend upon datatype. It is same for all. 
*/

#include <iostream>
using namespace  std;

int main(){
    int a = 10;
    int b = 20;
    cout << "&a: " << &a << endl;
    cout << "&b: " << &b << "\n\n";

    int *p = &a;              // declaration + initializaton
    int *pt;                  // declaration   [currently storing garbage value]

    /* 
       Sometimes it is useful to make our pointers point to nothing. This is called a null pointer. 
       We assign a pointer a null value by setting it to address 0.  
    */
    int *ptr = 0;             // NULL pointer

    // store the address of variable a
    ptr = &a;                           // assignment
    cout << "ptr: " << ptr << endl;

    // Re-assign another address to ptr pointer
    ptr = &b;
    cout << "ptr: " << ptr << endl;

    return 0;
}

/* 
OUTPUT: 

    &a: 0x7fff1ce2db00
    &b: 0x7fff1ce2db04

    ptr: 0x7fff1ce2db00
    ptr: 0x7fff1ce2db04


More About Pointers:

- Pointer & Arithmetic
    > Addition, Multiplication, Division of two addresses doesn’t make any sense
    > Addition of an address by a constant integer value 
      i.e. ptr +5 means address of cell which is 5 * sizeof(*ptr) away from ptr.
    > Similar for subtraction
    > Again Multiplying/Dividing an address with some constant value doesn’t make any sense
    > Subtracting two address of same type would give you number of elements between them

- Arrays & Pointers
    > An Array is actually a pointer that points to the first element of the array! 
      Because the array variable is a pointer, you can dereference it, which returns array element 0.
    > a[i] is same as *(a + i)

- Difference – Arrays & Pointers
    - The sizeof operator
        > sizeof(array) returns the amount of memory used by all elements in array
        > sizeof(pointer) only returns the amount of memory used by the pointer variable itself
    
    - The & operator
        > &array is an alias for &array[0] and returns the address of the ﬁrst element in array
        > &pointer returns the address of pointer
    
    - String literal initialization of a character array
        > char array[] = “abc” sets the ﬁrst four elements in array to ‘a’, ‘b’, ‘c’, and ‘\0′
        > char *pointer = “abc” sets pointer to the address of the “abc” string 
          (which may be stored in read-only memory and thus unchangeable)
    
    - Assignment/Re-assigment
        > Pointer variable can be assigned a value whereas array variable cannot be.
          Eg:  int a[10];
               int *p;
               p=a;     // legal
               a=p;     // illegal
    
    - Arithmetic
        > Arithmetic on pointer variable is allowed but array can’t be incremented/decremented.
          Eg:  p++;     // legal
               a++;     // illegal
*/
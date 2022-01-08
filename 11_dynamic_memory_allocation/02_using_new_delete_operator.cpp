/* 
    Topic - Using new & delete operator

    - new Operator
        > To allocate space dynamically, use the unary operator "new", followed by the type being allocated.
          Eg:   new int;           // dynamically allocates an int
                new double;        // dynamically allocates a double

        > If creating an Array dynamically, use the same form, but put brackets with a size after the type:
          Eg:   new int[40];       // allocates an array of 40 ints
                new double[size];  // allocates an array of [size] doubles
   
    - delete operator
        > To de-allocate memory that was created with 'new', we use the unary operator 'delete'. 
          The one operand should be a pointer that stores the address of the space to be deallocated:
          Eg:   int * ptr = new int;      // dynamically created int
                delete ptr;               // deletes the space that ptr points to

*/

#include <iostream>
using namespace  std;


int main(){
    /* 
        Allocate Memory using 'new' operator
    */

    int *p;            // declare a pointer p
    p = new int;       // dynamically allocate an int and load address into p

    double *d;         // declare a pointer d
    d = new double;    // dynamically allocate a double and load address into d

    // we can also do these in single line statements 
    int x = 40;
    int *list = new int[x];
    float *numbers = new float[x+10];


    /* 
        Freeup Memory using 'delete' operator
    */    

    delete p;          // deletes the space that ptr points to
    delete d;          // deletes the space that ptr points to
    delete [] list;    // deallocates the array
    delete [] numbers;    // deallocates the array

    /* Note that the pointers (p,d & list) still exists. 
       As, that’s a named variable subject to scope and extent determined at compile time. 
       So, we can Reuse the pointers */
    int num = 10;
    
    p = &num;          // 'p' pointing towards bucket num
    d = 0;             // resetting 'd' to null pointer
    list = 0;          // resetting 'list' to null pointer
    numbers = 0;       // resetting 'numbers' to null pointer

    cout << "num : " << num << endl;
    cout << "*p : " << *p << "\n\n";


    /* 
        'new' Operator & Initilizing values
    */
    // Example- 1
    int *n = new int(74);          // initilization with value 74
    cout << "Value of n : " << *n << "\n\n";
    delete n;                         // deallocate memory

    // Example- 2
    char *ch = new char('B');          // initilization with character 'B'
    cout << "Value of ch : " << *ch << "\n\n";
    delete ch;                         // deallocate memory

    // Example- 3
    int size;
    cout << "Enter Array Size: ";
    cin >> size;
    
    int *arr = new int[size]{1,2,3};        // initilization
    cout << "Array Elements: ";
    for(int idx=0; idx<=size-1; idx++){
    //   cout  << arr[idx] << " ";
      cout  << *(arr+idx) << " ";
    }
    
    delete [] arr;                      // deallocate memory

    cout << endl;
    return 0;
}

/* 
OUTPUT:

    num : 10
    *p : 10

    Value of n : 74

    Value of ch : B

    Enter Array Size: 6
    Array Elements: 1 2 3 0 0 0 
*/
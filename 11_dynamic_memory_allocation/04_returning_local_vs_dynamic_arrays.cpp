/* 
    Topic - Returning Local Arrays Vs Dynamic Arrays
*/

#include <iostream>
using namespace  std;


int* fun1(){
    int *a = new int[5]{1,2,3,4,5};    // Dynamic allocation

    cout << "a: " << a << endl;               // Output: [Address of a]
    cout << "a[0]: " << a[0] << endl;         // Output: 1
    
    return a;     

}

int* fun2(){
    int a[] = {1,2,3,4,5};             // Static allocation

    cout << "a: " << a << endl;               // Output: [Address of a]
    cout << "a[0]: " << a[0] << endl;         // Output: 1
    
    /* NOTE: we should never return  a local variable because once's the function call
             is over, the array is destroyed */
    return a;     
}


int main(){
    // Returning Dynamic Array
    cout << "Dynamic Allocation: \n";
    int *b = fun1();
    cout << "b: " << b << endl;             // Output: [Address of a]
    cout << "b[0]: " << b[0] << "\n\n";     // Output: 1
    delete [] b;

    // Returning Static Array
    cout << "Static Allocation: \n";
    b = fun2();
    cout << "b: " << b << endl;             // Output: [Address of a]
    cout << "b[0]: " << b[0] << endl;       // Output: [Garbage or Segmentaion Fault]
    
    /* In above case, fun2() return a local variable (as a[] is a static allocation) 
       So, once's the function call is over, the array is destroyed. 
       Thus, we cannot guess the output for b[0] */

    return 0;
}

/* 
OUTPUT: 
  Dynamic Allocation: 
    a: 0x55cf8b0902c0
    a[0]: 1
    b: 0x55cf8b0902c0
    b[0]: 1

  Static Allocation: 
    a: 0x7ffd78bdd240
    a[0]: 1
    b: 0
    Segmentation fault (core dumped)
*/
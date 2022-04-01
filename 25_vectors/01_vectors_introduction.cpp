/* 
    TOPIC: Vectors - Introduction

    What is a Vector ?
    - Vectors are same as dynamic arrays with the ability to resize itself automatically.
      when an element is inserted or deleted, their storage being handled automatically by the container. 
      (i.e Vector is a Dynamic Array, that can grow & shrink in size.)

    - Vector elements are placed in contiguous storage so that they can be accessed and traversed
      using iterators. 

    - Vectors are part of the C++ Standard Template Library. To use vectors, we need to include
      the vector header file in our program.
      #include<vector>

    - After that, we can construct vector objects. 

*/


#include<iostream>
#include<vector>
using namespace std;


int main()
{
    // How to create & initalise a vector (object)
    vector<int> a;
    vector<int> b(5,10);       // five int with value 10. Useful when initilizing vector of zeros (n,0)
    vector<int> c(b.begin(), b.end());
    vector<int> d{1,2,3,10,14};

    // How to iterate over vector
    cout << "vector c: ";
    for(int i=0; i<c.size(); i++)                 // size(): gives how many elements vector contains
    {
        cout << c[i] << " ";
    }
    cout << endl;

    // iterate using For each Loop 
    cout << "vector d: ";
    for(int x:d)
    {
        cout << x << " ";
    }
    cout << endl;

    // Iterate using Iterator
    cout << "vector b: ";
    for(auto it = b.begin(); it != b.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    /* NOTE: There is a class "vector" and inside that class, "iterator" is defined .
             So, to iterate over vector, we have to create a iterator of this perticular type.
             Eg: vector<int>::iterator
             So, if we want to replace "auto" in the above loop. we have to type the 
             complete name: vector<int>::iterator
     */

    // Discuss more functions
    vector<int> v;
    int n;
    cout << "Enter vector size: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
      int no;
      cin >> no;
      v.push_back(no);                // push_back(inp): Adds an element to the ends of vector
    }

   /* NOTE: The vector size get double after the push_back operation in C++ */

    cout << "Vector v: ";
    for(int x:v)
    {
      cout << x << " ";
    }
    cout << endl;


    // Understand at memory level, what are the difference in the two vector d & v?
    cout << "v.size(): " << v.size() << endl;          // number of elements 
    cout << "v.capacity(): " << v.capacity() << endl;  // size of underlying array
    cout << "v.max_size(): " << v.max_size() << endl;  // Maximun no of elements a vector can hold in worst case
                                                       // according to available memory in the system
    cout << "d.size(): " << d.size() << endl;        
    cout << "d.capacity(): " << d.capacity() << endl;
    cout << "d.max_size(): " << d.max_size() << endl;

    /* NOTE: d.capacity() = 5   but   v.capacity() = 8  because 
             in vector v, we are using push_back() function,
             so, the vector size get double after the push_back operation.
    */


    return 0;
}


/* 
OUTPUT:

    vector d: 1 2 3 10 14 
    vector b: 10 10 10 10 10 

    Enter vector size: 5
    Enter elements: 10 20 30 40 50
    Vector v: 10 20 30 40 50 

    v.size(): 5
    v.capacity(): 8
    v.max_size(): 2305843009213693951
    
    d.size(): 5
    d.capacity(): 5
    d.max_size(): 2305843009213693951

*/
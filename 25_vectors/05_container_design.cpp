/* 
    TOPIC: Container Design

    We will be designing our own vector class.
    To understand, How STL containers are implemented ?

    Note: first view "vector.h" file
*/

// Using user defined vector class

#include<iostream>                  // using <> for standard header files
#include "vector.h"                 // using "" for user defined files
// #include "../25_vectors/vector2.h"
using namespace std;

int main()
{
    Vector v;

    v.push_back(11);
    v.push_back(12);
    v.push_back(13);
    v.push_back(14);
    v.pop_back();
    v.push_back(15);
    
    cout << "v.capacity: " << v.capacity() << endl;
    v.push_back(20);
    cout << "v.capacity: " << v.capacity() << endl;

    cout << "Vector v: ";
    for(int i=0; i< v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout << "v.size: " << v.size() << endl;

    return 0;
}

/* 
OUTPUT:

    v.capacity: 4
    v.capacity: 8

    Vector v: 11 12 13 15 20 

    v.size: 5
*/